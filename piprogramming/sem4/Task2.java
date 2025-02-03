package sem4;

import java.io.FileWriter;
import java.io.IOException;

public class Task2 {
    public interface Logger {
        void log(String message);
    }

    public static class ConsoleLogger implements Logger {
        @Override
        public void log(String message) {
            System.out.println("Console log: " + message);
        }
    }

    public static class FileLogger implements Logger {
        private String fileName;

        public FileLogger(String fileName) {
            this.fileName = fileName;
        }

        @Override
        public void log(String message) {
            try (FileWriter writer = new FileWriter(fileName, true)) {
                writer.write("File log: " + message + System.lineSeparator());
                System.out.println("Message logged to file: " + fileName);
            } catch (IOException e) {
                System.err.println("Failed to write to file: " + e.getMessage());
            }
        }
    }

    public static class Application {
        private final Logger logger;

        public Application(Logger logger) {
            this.logger = logger;
        }

        public void logInfo(String message) {
            logger.log(message);
        }
    }

    public static void main(String[] args) {
        Logger consoleLogger = new ConsoleLogger();
        Application app1 = new Application(consoleLogger);
        app1.logInfo("console log");

        Logger fileLogger = new FileLogger("logfile.txt");
        Application app2 = new Application(fileLogger);
        app2.logInfo("file log");
    }
}
