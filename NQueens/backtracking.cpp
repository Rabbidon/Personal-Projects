#include <iostream>
#include <vector>
#include "backtracking.h"

using namespace std;

bool isSolution(vector<int>& boardState,int n)
{
    int finalPlaced = (boardState.size())-1;
    for (int i=0; i<finalPlaced; i++)
    {
        if ((boardState[i] == boardState[finalPlaced])||(abs(boardState[i]-boardState[finalPlaced])==(finalPlaced-i)))
        {
            return false;
        }
    }
    if (finalPlaced == n-1)
    {
        for (int i : boardState)
        {
            cout << i << endl;
        }
        exit(-1);
    }
    for (int i=0; i<n; i++)
    {
        boardState.push_back(i);
        if(isSolution(boardState,n))
        {
            return true;
        }
        boardState.pop_back();
    }
    return false;
}
