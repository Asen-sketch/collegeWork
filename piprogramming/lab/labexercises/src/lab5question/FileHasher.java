package lab5question;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;

public class FileHasher {

    public int hashFileContent(String filePath) throws IOException {
        File file = new File(filePath);
        if (!file.exists() || !file.isFile()) {
            throw new IllegalArgumentException("bad path: " + filePath);
        }

        int hash = 0;
        try (FileInputStream fis = new FileInputStream(file)) {
            int byteData;
            while ((byteData = fis.read()) != -1) {
                hash ^= byteData;
            }
        }
        return hash;
    }

    public boolean areFilesEqual(String filePath1, String filePath2) throws IOException {
        int hash1 = hashFileContent(filePath1);
        int hash2 = hashFileContent(filePath2);
        return hash1 == hash2;
    }

    public static void main(String[] args) {
        try {
            FileHasher hasher = new FileHasher();
            String file1 = "file1.txt";
            String file2 = "file2.txt";

            int hash1 = hasher.hashFileContent(file1);
            int hash2 = hasher.hashFileContent(file2);

            System.out.println("hash file1: " + hash1);
            System.out.println("hash file2: " + hash2);

            if (hasher.areFilesEqual(file1, file2)) {
                System.out.println("equal");
            } else {
                System.out.println("diff");
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
