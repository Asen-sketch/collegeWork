package lab4;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

abstract class Course {
    String courseName;
    Student[] students;
    int studentCount;

    public Course(String courseName) {
        this.courseName = courseName;
        this.students = new Student[5];
        this.studentCount = 0;
    }

    public void addStudent(Student student) {
        if (studentCount < students.length) {
            students[studentCount++] = student;
        } else {
            System.out.println("The course is full");
        }
    }

    public abstract double calcAvg();

    public void saveToFile(String filePath) throws IOException {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filePath))) {
            writer.write("Course: " + courseName + "\n");
            for (int i = 0; i < studentCount; i++) {
                writer.write("Student name: " + students[i].getName() + ", grades: ");
                for (int grade : students[i].getGrades()) {
                    writer.write(grade + " ");
                }
                writer.write("\n");
            }
            System.out.println("Saved: " + filePath);
        }
    }
}

class Mathematics extends Course {
    public Mathematics() {
        super("Mathematics");
    }

    @Override
    public double calcAvg() {
        double total = 0;
        for (int i = 0; i < studentCount; i++) {
            total += students[i].calcAvg();
        }
        return studentCount > 0 ? total / studentCount : 0;
    }
}

class Informatics extends Course {
    public Informatics() {
        super("Informatics");
    }

    @Override
    public double calcAvg() {
        double total = 0;
        for (int i = 0; i < studentCount; i++) {
            total += students[i].calcAvg();
        }
        return studentCount > 0 ? total / studentCount : 0;
    }
}

class Student {
    private String name;
    private int[] grades;

    public Student(String name, int[] grades) {
        this.name = name;
        this.grades = grades;
    }

    public String getName() {
        return name;
    }

    public int[] getGrades() {
        return grades;
    }

    public double calcAvg() {
        int sum = 0;
        for (int grade : grades) {
            sum += grade;
        }
        return grades.length > 0 ? (double) sum / grades.length : 0;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        Course math = new Mathematics();
        Course info = new Informatics();

        System.out.println("Register math students:");
        registerStudents(scanner, math);

        System.out.println("Register informatics students:");
        registerStudents(scanner, info);

        saveCourseData(math, "math.txt");
        saveCourseData(info, "informatics.txt");
        saveAverageData(math, info, "average.txt");

        scanner.close();
    }

    private static void registerStudents(Scanner scanner, Course course) {
        for (int i = 1; i <= 5; i++) {
            System.out.print("Student " + i + " name: ");
            String name = scanner.next();
            System.out.print("Enter 3 grades separated by spaces: ");
            int[] grades = new int[3];
            for (int j = 0; j < 3; j++) {
                grades[j] = scanner.nextInt();
            }
            course.addStudent(new Student(name, grades));
        }
    }

    private static void saveCourseData(Course course, String filePath) {
        try {
            course.saveToFile(filePath);
        } catch (IOException e) {
            System.out.println("File error: " + e.getMessage());
        }
    }

    private static void saveAverageData(Course math, Course info, String filePath) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filePath))) {
            writer.write("Math average: " + math.calcAvg() + "\n");
            writer.write("Informatics average: " + info.calcAvg() + "\n");
            System.out.println("Averages saved to " + filePath);
        } catch (IOException e) {
            System.out.println("File error: " + e.getMessage());
        }
    }
}
