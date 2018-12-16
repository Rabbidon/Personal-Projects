#include <iostream>
#include "fitness.h"

using namespace std;

int fitness(vector<int> boardState)
{
	int n = boardState.size();
	int fitnessScore = 0;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<i; j++)
		{
			if(abs(boardState[i]-boardState[j])==(i-j))
			{
				fitnessScore++;
			}
		}
	}
	return fitnessScore;
}
