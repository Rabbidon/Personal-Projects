// Starts a game instance. This should be able to run in a shell which determines the output - command line or GUI.
// Each game instance has a fixed word generation method. I hope to add support for a web scraper at some point, so there should be a get word method.

// This is also built with the notion that the shell doesn't know what the target word is, or how to.

import java.util.*;
import java.util.concurrent.ThreadLocalRandom;
import java.util.stream.Collectors;

public class GameInstance
{
    // The word bank from which we randomly pick the target word.
    private static String[] wordBank = {"alpha","bravo","charlie","delta","echo","foxtrot","golf","hotel","india","juliett","kilo","lima","mike","november","oscar","papa","quebec","romeo","sierra","tango","uniform","victor","whiskey","xray","yankee","zulu"};

    // Store all chars tried thus far
    private Set<Integer> lettersTried = new HashSet();

    // Stores the target word (which we are trying to guess)
    private String targetWord = "";

    private int startingLives;

    // Default constructor
    public GameInstance(int lives)
    {
        startingLives = lives;
    }

    // This randomly selects a word from the word bank.
    public void generateWord()
    {
        targetWord = wordBank[ThreadLocalRandom.current().nextInt(0, 26)];
    }

    // This method handles queries from the shell.
    public int handle(char c)
    {
        if (lettersTried.contains((int)c)){return -1;}
        lettersTried.add((int)c);
        if (targetWord.indexOf(c)==-1) {return 0;}
        return 1;
    }

    // Allows us to access the life counter
    public int getLives()
    {
        Set<Integer> guessedRight = new HashSet(targetWord.chars().boxed().collect(Collectors.toList()));
        guessedRight.retainAll(lettersTried);
        return startingLives - (lettersTried.size()-guessedRight.size());
    }

    // Allows us to access the set of letters we have already tried
    public Set<Integer> getLettersTried() { return lettersTried; }

    public String getTargetWord() {return targetWord;}

    // Gives us the dashed string
    public String getDashString()
    {
        StringBuilder dashString = new StringBuilder();
        for (int i=0; i<targetWord.length(); i++)
        {
            if (lettersTried.contains((int)(targetWord.charAt(i)))){dashString.append(targetWord.charAt(i));}
            else {dashString.append('-');}
        }
        return dashString.toString();
    }

    public boolean victoryCondition() {return lettersTried.containsAll(new HashSet(targetWord.chars().boxed().collect(Collectors.toList())));}

}
