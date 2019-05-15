// Starts a game instance. This should be able to run in a shell which determines the output - command line or GUI.
// For now we will use a preselected dictionary. I hope to add support for a web scraper at some point, so there should be a get word method.

import java.util.List;
import java.util.ArrayList;

public class GameInstance
{

    static String[] wordBank = {"alpha","bravo","charlie","delta","echo","foxtrot","golf","hotel","india","juliett","kilo","lima","mike","november","oscar","papa","quebec","romeo","sierra","tango","uniform","victor","whiskey","xray","yankee","zulu"};

    private List<String> lettersTried = new ArrayList();

    public void input(String input)
    {

    }

}
