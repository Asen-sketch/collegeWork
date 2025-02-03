package sem5;

import java.io.PrintWriter;
import java.io.Serializable;
import java.util.Scanner;

public abstract class User implements Serializable {
    protected String username;
    protected String password;

    public User(String username, String password) {
        this.username = username;
        this.password = password;
    }

    public String getUsername() {
        return username;
    }

    public boolean validatePassword(String password) {
        return this.password.equals(password);
    }

    public abstract void showMenu(Library library, PrintWriter writer, Scanner scanner);
}
