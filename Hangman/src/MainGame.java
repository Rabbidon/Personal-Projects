// This is the main class. It acts as a shell in which the game instance runs.
// This is the shell for the command line version.

import java.util.*;
import java.util.Scanner;

public class MainGame
{
    public static void main(String[] args) {
        System.out.println("Welcome to Command Line Hangman!");
        System.out.println("Please type \"n\" to start or \"x\" to close the program");
        Scanner scan = new Scanner(System.in);
        while (true)
        {
            if (scan.hasNextLine())
            {
                String tmp = scan.nextLine();
                if (tmp.equals("n"))
                {
                    break;
                }
                if (tmp.equals("x"))
                {
                    return;
                }
            }
        }
        GameInstance game = new GameInstance();
        while (true)
        {
            game.resetLives();
            game.resetLettersTried();
            System.out.println("Generating word...");
            game.generateWord();
            StringBuilder dashString = new StringBuilder(new String(new char[game.getWordLength()]).replace("\0", "- "));
            System.out.println("The word to guess is "+ dashString);
            System.out.println("Guess letters by entering single lower-case English letters into the command line");
            while (true)
            {
                if (scan.hasNextLine())
                {
                    String tmp = scan.nextLine();
                    List<Integer> instructions = game.handle(tmp);

                    switch (instructions.get(0))
                    {
                        case -3: System.out.println("Invalid input: please enter a lower-case English letter"); break;
                        case -2: System.out.println("You have already tried this letter. The letters that you have tried already are {"+ String.join(",", game.getLettersTried())+"}"); break;
                        case -1: System.out.println("Letter not present in target word. You have "+game.getLives()+" lives remaining"); break;
                        default:
                            for (int i : instructions)
                            {
                                dashString.setCharAt(2*i, tmp.charAt(0));
                            }
                            System.out.println("Letter present in target word. You have "+game.getLives()+" lives remaining"); break;
                    }
                    if (game.getLives()==0)
                    {
                        System.out.println("You have run out of lives. You may start a new game (Enter \"n\") or quit (Enter \"x\")");
                        break;
                    }
                    if (game.checkWinCondition())
                    {
                        int dashPointer = 0;
                        while (dashPointer<dashString.length())
                        {
                            if (dashString.charAt(dashPointer)==' ') {dashString.deleteCharAt(dashPointer);}
                            else {dashPointer++;}
                        }
                        System.out.println("You win! The target word was \""+dashString+"\"");
                        System.out.println("You may start a new game (Enter \"n\") or quit (Enter \"x\")");
                        break;
                    }
                    System.out.println("The word to guess is \""+ dashString+"\"");
                    System.out.println("Guess letters by entering single lower-case English letters into the command line");
                }
            }
            while (true)
            {
                if (scan.hasNextLine())
                {
                    String tmp = scan.nextLine();
                    if (tmp.equals("n"))
                    {
                        break;
                    }
                    if (tmp.equals("x")) {
                        return;
                    }
                }
            }
        }
    }

}
