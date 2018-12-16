#include <iostream>
#include <vector>
#include "fitness.h"
#include "heuristic.h"
#include "annealing.h"
#include <math.h>

using namespace std;

int main()
{
    srand(time(0));
    vector<int> boardState = {};
    for (int i=0; i<40; i++)
    {
        boardState.push_back(i);
    }
    anneal(boardState,0.01,10);

    return 0;
}

void anneal(std::vector<int> boardState, float a, float T)
//a is cooling ratio, T is temperature
{
    while (fitness(boardState)>0)
    {
        vector<int> adjacent = neighbour(boardState);
        if (fitness(adjacent) < fitness(boardState))
        {
            boardState = adjacent;
        }
        else
        {
            float r = (rand()%10000)/10000;
            if (r<exp((fitness(boardState)-fitness(adjacent))/T))
            {
                boardState = adjacent;
            }
        }
        T = a*T;
    }
    for (int i : boardState)
    {
        cout << i << endl;
    }
}
