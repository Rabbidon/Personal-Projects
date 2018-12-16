#include <iostream>
#include <deque>
#include <math.h>
#include "tabusearch.h"
#include "fitness.h"
#include <algorithm>

int main()
{
    std::vector<int> boardState = {};
    for (int i=0; i<60; i++)
    {
        boardState.push_back(i);
    }
    tabusearch(boardState,30);

    return 0;
}

 void tabusearch(std::vector<int> boardState, int tabooDuration)
 {
 	int n = boardState.size();

 	vector<int> defaultBoard;
 	for (int i = 0; i<n; i++)
 	{
 		defaultBoard.push_back(i);
 	}
 	deque<vector<int>> tabooList;
 	for (int i = 0; i<tabooDuration; i++)
 	{
 		tabooList.push_back(vector<int> {n,n});
 	}
 	int fit = n*n;
 	while (fit>0)
 	{
 		vector<std::vector<int>> neighbourhood;
 		fit = n*n;
 		vector<int> tabooProperty;
 		vector<int> neighbour = defaultBoard;
 		for (int i = 0; i<n; i++)
 		{
 			for (int j = 0; j<n; j++)
 			{
 				if (tabooList.end() == find(tabooList.begin(),tabooList.end(),vector<int> {i,j}))
 				{
		 			int temp = boardState[i];
			 		boardState[i] = boardState[j];
			 		boardState[j] = temp;
			 		if (fitness(boardState)<fit)
			 		{
			 			fit = fitness(boardState);
			 			tabooProperty = {i,j};
			 			neighbour = boardState;
			 		}
			 		boardState[j] = boardState[i];
			 		boardState[i] = temp;
			 	}
 			}
 		}
 		tabooList.push_back(tabooProperty);
 		tabooList.pop_front();
 		boardState = neighbour;
 	}
 	for (int i : boardState)
    {
        cout << i << endl;
    }
    return;
 }