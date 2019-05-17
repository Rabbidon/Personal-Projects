// Starts a game instance. This should be able to run in a shell which determines the output - command line or GUI.
// Each game instance has a fixed word generation method. I hope to add support for a web scraper at some point, so there should be a get word method.

// This is also built with the notion that the shell doesn't know what the target word is, or how to.

import java.util.*;
import java.util.concurrent.ThreadLocalRandom;

public class GameInstance
{
    // The word bank from which we randomly pick the target word.
    private String[] wordBank = {"alpha","bravo","charlie","delta","echo","foxtrot","golf","hotel","india","juliett","kilo","lima","mike","november","oscar","papa","quebec","romeo","sierra","tango","uniform","victor","whiskey","xray","yankee","zulu"};

    // Store all chars tried thus far
    private Set<String> lettersTried = new HashSet();

    // Stores the target word (which we are trying to guess)
    private Map<Character,List<Integer>> wordMap = new HashMap<Character,List<Integer>>();

    // Stores the number of lives the player has
    private int lives;

    private int wordLength=0;

    // Keeps track of the characters that the player has yet to guess
    private Set posToGuess = new HashSet<>();

    private final int livesDefault = 8;

    // Default constructor
    public GameInstance()
    {
        lives = livesDefault;
    }

    // This randomly selects a word from the word bank. wordLength is set to the length of the new word.
    public void generateWord()
    {
        wordLength = 0;
        wordMap.clear();
        posToGuess = new HashSet<>();
        String myWord = wordBank[ThreadLocalRandom.current().nextInt(0, 26)];
        for (int i=0; i<myWord.length(); i++)
        {

            List<Integer> entry = wordMap.getOrDefault(myWord.charAt(i),new ArrayList<Integer>());
            entry.add(i);
            wordMap.put(myWord.charAt(i),entry);
            posToGuess.add(i);
            wordLength++;
        }
    }

    // This method handles queries from the shell.
    public List<Integer> handle (String input)
    {
        List posList = new ArrayList<Integer>();

        if (input.length()!=1)    {posList.add(-3); return posList;}

        char tmp = input.charAt(0);

        if (((int)tmp<'a') | ((int)tmp>'z'))    {posList.add(-3); return posList;}

        if (lettersTried.contains(Character.toString(tmp)))     {posList.add(-2); return posList;}

        lettersTried.add(Character.toString(tmp));

        if (wordMap.containsKey(tmp))
        {
            for (int i : wordMap.get(tmp))
            {
                posToGuess.remove(i);
            }
            return wordMap.get(tmp);
        }

        posList.add(-1);
        lives--;
        return posList;
    }

    // Resets the life counter
    public void resetLives() {lives = livesDefault;}

    // Resets the set of letter that are labelled as "already tried"
    public void resetLettersTried() {lettersTried = new HashSet();}

    // Allows us to access the life counter
    public int getLives() { return lives; }

    public int getWordLength() { return wordLength; }

    // Allows us to access the set of letters we have already tried
    public Set getLettersTried() { return lettersTried; }

    public boolean checkWinCondition()
    { return posToGuess.isEmpty(); }

}
