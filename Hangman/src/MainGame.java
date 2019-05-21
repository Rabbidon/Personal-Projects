// This is the main class. It acts as a shell in which the game instance runs.
// This is the shell for the command line version.

import java.util.*;
import java.util.stream.*;
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
        while (true)
        {
            GameInstance game = new GameInstance(8);
            System.out.println("Generating word...");
            game.generateWord();
            System.out.println("The word to guess is "+ game.getDashString());
            System.out.println("Guess letters by entering single lower-case English letters into the command line");
            while (true)
            {
                if (scan.hasNextLine())
                {
                    String tmp = scan.nextLine();
                    if (tmp.length()!=1) {System.out.println("Invalid input: please enter a lower-case English letter");}
                    else
                    {
                        char c = tmp.charAt(0);
                        if (!(c>='a' && c<='z')) {System.out.println("Invalid input: please enter a lower-case English letter");}
                        else
                        {
                            int response = game.handle(c);
                            switch (response)
                            {
                                case -1:
                                    System.out.println("You have already guessed this letter. The letters you have already guessed are ["
                                    +String.join(",",game.getLettersTried().stream().map(i -> Character.toString((char)(i.intValue()))).collect(Collectors.toList()))+"]");
                                    break;

                                case 0:
                                    System.out.println("Letter not present in word. The word to guess is "+game.getDashString()+". You have "+game.getLives()+" lives remaining");
                                    break;

                                default:
                                    System.out.println("Letter present in word. The word to guess is "+game.getDashString()+". You have "+game.getLives()+" lives remaining");
                            }
                        }
                    }

                    if (game.getLives()==0)
                    {
                        System.out.println("You have run out of lives. You lose. The target word was "+game.getTargetWord());
                        System.out.println("You may start a new game (Enter \"n\") or quit (Enter \"x\")");
                        break;
                    }
                    if (game.victoryCondition())
                    {
                        System.out.println("You win! The target word was "+ game.getTargetWord());
                        System.out.println("You may start a new game (Enter \"n\") or quit (Enter \"x\")");
                        break;
                    }
                    System.out.println("The word to guess is "+ game.getDashString());
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
