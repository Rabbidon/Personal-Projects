// Starts a game instance. This should be able to run in a shell which determines the output - command line or GUI.
// Each game instance has a fixed word generation method. I hope to add support for a web scraper at some point, so there should be a get word method.

// This is also built with the notion that the shell doesn't know what the target word is, or how to.

import java.util.HashSet;
import java.util.List;
import java.util.ArrayList;
import java.util.Set;
import java.util.concurrent.ThreadLocalRandom;

public class GameInstance
{
    // The word bank from which we randomly pick the target word.
    private String[] wordBank = {"alpha","bravo","charlie","delta","echo","foxtrot","golf","hotel","india","juliett","kilo","lima","mike","november","oscar","papa","quebec","romeo","sierra","tango","uniform","victor","whiskey","xray","yankee","zulu"};

    // Store all chars tried thus far
    private Set<Character> lettersTried = new HashSet();

    // Stores the target word (which we are trying to guess)
    private char[] targetWord = null;

    // Stores the number of lives the player has
    private int lives;

    private final int livesDefault = 8;

    // Default constructor
    public GameInstance()
    {
        lives = livesDefault;
    }

    // This randomly selects a word from the word bank
    public void getWord()
    {
        targetWord = wordBank[ThreadLocalRandom.current().nextInt(0, 26)].toCharArray();
    }

    // This method handles queries from the shell.
    public Iterable<Integer> handle (String input)
    {
        List posList = new ArrayList<Integer>();

        if (input.length()!=1)    {posList.add(-3); return posList;}

        char tmp = input.charAt(0);

        if (!(((int)tmp<'a') | ((int)tmp>'z')))    {posList.add(-3); return posList;}

        if (lettersTried.contains(tmp))     {posList.add(-2); return posList;}

        boolean charNotFound = true;
        for (int i=0; i<targetWord.length; i++)
        {
            if (targetWord[i] == tmp)    {charNotFound = false; posList.add(i);}
        }
        if (charNotFound)    {posList.add(-1); lives--; posList.add(lives);}

        return posList;
    }

    // Resets the life counter
    public void resetLives() {lives = livesDefault;}

    // Allows us to access the life counter
    public int getLives()
    {
        return lives;
    }

    // Allows us to access the set of letters we have already tried
    public Set getLettersTried()
    {
        return lettersTried;
    }
}
