package word1;

import java.util.Scanner;

public class ProjectPlanning {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String architectName = scanner.nextLine();
        int projects = scanner.nextInt();
        int hours = projects * 3;
        System.out.printf("The architect %s will need %d hours to complete %d project/s.", architectName, hours, projects);
    }
}
