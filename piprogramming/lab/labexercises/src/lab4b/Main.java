package lab4b;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

interface Visit {
    Date getDate();
    String getUrl();
}

class VisitImpl implements Visit {
    private Date date;
    private String url;

    public VisitImpl(String dateStr, String url) throws ParseException {
        SimpleDateFormat format = new SimpleDateFormat("dd.MM.yyyy HH:mm:ss");
        this.date = format.parse(dateStr);
        this.url = url;
    }

    public Date getDate() {
        return date;
    }

    public String getUrl() {
        return url;
    }
}

class Website {
    private String url;
    private int visitCount;

    public Website(String url) {
        this.url = url;
        this.visitCount = 0;
    }

    public String getUrl() {
        return url;
    }

    public int getVisitCount() {
        return visitCount;
    }

    public void incrementVisit() {
        visitCount++;
    }
}

class WebsiteStatistics {
    private static final int MAX_DATES = 30;
    private static final int MAX_WEBSITES = 10;
    private String[] dates = new String[MAX_DATES];
    private Website[][] websites = new Website[MAX_DATES][MAX_WEBSITES];
    private int[] totalVisitsPerDate = new int[MAX_DATES];
    private int dateCount = 0;

    public void addVisit(Visit visit) {
        String dateKey = new SimpleDateFormat("dd.MM.yyyy").format(visit.getDate());

        int dateIndex = findOrAddDate(dateKey);
        if (dateIndex == -1) {
            System.out.println("date limit reached");
            return;
        }

        int websiteIndex = findOrAddWebsite(dateIndex, visit.getUrl());
        if (websiteIndex == -1) {
            System.out.println("web limit reached for date " + dateKey);
            return;
        }

        websites[dateIndex][websiteIndex].incrementVisit();
        totalVisitsPerDate[dateIndex]++;
    }

    private int findOrAddDate(String dateKey) {
        for (int i = 0; i < dateCount; i++) {
            if (dates[i].equals(dateKey)) {
                return i;
            }
        }
        if (dateCount < MAX_DATES) {
            dates[dateCount] = dateKey;
            return dateCount++;
        }
        return -1;
    }

    private int findOrAddWebsite(int dateIndex, String url) {
        for (int i = 0; i < MAX_WEBSITES; i++) {
            if (websites[dateIndex][i] != null && websites[dateIndex][i].getUrl().equals(url)) {
                return i;
            } else if (websites[dateIndex][i] == null) {
                websites[dateIndex][i] = new Website(url);
                return i;
            }
        }
        return -1;
    }

    public void analyzeVisits() {
        for (int i = 0; i < dateCount; i++) {
            System.out.println("Date: " + dates[i] + ", Total Visits: " + totalVisitsPerDate[i]);

            Website leastVisited = null;
            for (int j = 0; j < MAX_WEBSITES; j++) {
                if (websites[i][j] != null) {
                    if (leastVisited == null || websites[i][j].getVisitCount() < leastVisited.getVisitCount()) {
                        leastVisited = websites[i][j];
                    }
                }
            }

            if (leastVisited != null) {
                System.out.println("Least visited website on " + dates[i] + ": " + leastVisited.getUrl() +
                        " with " + leastVisited.getVisitCount() + " visits");
            }
        }
    }
}

public class Main {
    public static void main(String[] args) {
        WebsiteStatistics statistics = new WebsiteStatistics();
        String filePath = "visits.txt";

        try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
            String line;
            int lineNumber = 0;

            while ((line = reader.readLine()) != null) {
                lineNumber++;
                try {
                    String[] parts = line.split(" ");
                    if (parts.length < 3) {
                        throw new IllegalArgumentException("incorrect format: missing date, time, or URL");
                    }
                    String dateStr = parts[0] + " " + parts[1];
                    String url = parts[2];
                    Visit visit = new VisitImpl(dateStr, url);
                    statistics.addVisit(visit);
                } catch (ParseException e) {
                    System.out.println("Err on line " + lineNumber + ": Invalid date format.");
                } catch (IllegalArgumentException e) {
                    System.out.println("Err on line " + lineNumber + ": " + e.getMessage());
                }
            }

            statistics.analyzeVisits();

        } catch (IOException e) {
            System.out.println("Err reading the file: " + e.getMessage());
        }
    }
}
