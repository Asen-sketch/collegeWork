package ex2;

public class Company {
    private String name;
    private String creationDate;
    private String bulstat;

    public Company(String name, String creationDate, String bulstat) {
        this.name = name;
        this.creationDate = creationDate;
        setBulstat(bulstat);
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getCreationDate() {
        return creationDate;
    }

    public void setCreationDate(String creationDate) {
        this.creationDate = creationDate;
    }

    public String getBulstat() {
        return bulstat;
    }

    public void setBulstat(String bulstat) {
        if (bulstat.length() == 10) {
            this.bulstat = bulstat;
        } else {
            System.out.println("Error: Bulstat must be exactly 10 characters long.");
        }
    }
}