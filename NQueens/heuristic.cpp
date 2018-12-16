#include <iostream>
#include <vector>

using namespace std;

vector<int> neighbour(vector<int> boardState)
{
    int n = boardState.size();
    int a = rand()%n;
    int b = rand()%n;
    int temp = boardState[a];
    boardState[a] = boardState[b];
    boardState[b] = temp;
    return boardState;
}
