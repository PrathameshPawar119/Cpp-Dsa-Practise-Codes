#include <iostream>
#include <vector>
#include "../default_funcs.cpp"
using namespace std;

bool canPlace(vector<vector<int>> &maze, int n, int ptrx, int ptry, vector<vector<int>> &record)
{
    if((0 <= ptrx && ptrx < n) && (0 <= ptry && ptry < n) && record[ptrx][ptry] == 0 && maze[ptrx][ptry] == 1)
    {
        return true;
    }
    return false;
}

void solveRatInMaze(vector<vector<int>> &maze, int n, string path, int ptrx, int ptry, vector<string> &possibleSoln, vector<vector<int>> &record)
{
    if(ptrx == n-1 && ptry == n-1)
    {
        possibleSoln.push_back(path);
        return ;
    }

    // current point is visited 
    record[ptrx][ptry] = 1;

    // D   // R   // L   // U
    // r++ /  c++/   c-- / r--

    // Down
    if(canPlace(maze, n, ptrx+1, ptry, record))
    {
        path.push_back('D');
        solveRatInMaze(maze, n, path, ptrx+1, ptry, possibleSoln, record);
        path.pop_back();
    }   
    // Right
    if(canPlace(maze, n, ptrx, ptry+1, record))
    {
        path.push_back('R');
        solveRatInMaze(maze, n, path, ptrx, ptry+1, possibleSoln, record);
        path.pop_back();
    }  
    // Left
    if(canPlace(maze, n, ptrx, ptry-1, record))
    {
        path.push_back('L');
        solveRatInMaze(maze, n, path, ptrx, ptry-1, possibleSoln, record);
        path.pop_back();
    }  
    // Up
    if(canPlace(maze, n, ptrx+1, ptry, record))
    {
        path.push_back('U');
        solveRatInMaze(maze, n, path, ptrx+1, ptry, possibleSoln, record);
        path.pop_back();
    }  

    record[ptrx][ptry] = 0;  // clear record for next path finding
}


int main()
{
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    int n = 4;

    vector<vector<int>> record(n, vector<int>(n, 0));


    vector<string> possibleSoln;
    string path = "";

    solveRatInMaze(maze, n, path, 0, 0, possibleSoln, record);
    
    printStrVector(possibleSoln);

    return 0;
}