package ex4;

import java.util.regex.*;

public class Chessex {
    public static void main(String[] args) {
        String moves = "Nf3 Bb6 Qxd4 Rf1+ hello";
        checker(moves);
    }

    static void checker(String moves) {
        String regex = "\\b(?:[KQRBN]?[a-h]?[1-8]?x?[a-h][1-8][\\+\\#]?|O-O(-O)?)\\b";
        Pattern pattern = Pattern.compile(regex);

        String validMoves = "";
        String invalidMoves = "";

        for (String move : moves.split(" ")) {
            if (pattern.matcher(move).matches()) {
                validMoves += move + " ";
            } else {
                invalidMoves += move + " ";
            }
        }

        System.out.println("Valid moves: " + validMoves.trim());
        System.out.println("Invalid moves: " + invalidMoves.trim());
    }
}

