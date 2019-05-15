// This is the main class. It acts as a shell in which the game instance runs.
// This is the shell for the command line version.

import java.util.Scanner;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class MainGame
{
    public static void main(String[] args) throws IOException {
        System.out.println("Welcome to Command Line Hangman!");
        System.out.println("Please type \"Y\" to start or \"N\" to close the program");
        Scanner scan = new Scanner(System.in);
        while (true)
        {
            if (scan.hasNextLine())
            {
                String tmp = scan.nextLine();
                if (tmp == "x") {
                    break;
                }
                if (tmp == "q") {
                    return;
                }

            }
        }
    }

    public static void gameloop()
    {

    }
}
