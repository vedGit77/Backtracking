//Given a matrix...rat at top left corner(0,0) and cheese at bottom right corner
//0 in grid means theres a wall, and 1 means rat is free to pass
//rat can move from (i,j) to (i+1,j) or (i,j+1)
//find whether rat can reach the cheese...if yes, print the path

#include <bits/stdc++.h>
using namespace std;

#define N 4 
   
void printSolution(int sol[N][N]) 
{ 
    for (int i = 0; i < N; i++) 
    { 
        for (int j = 0; j < N; j++) 
            printf(" %d ", sol[i][j]); 
        printf("\n"); 
    } 
} 
  
bool isSafe(int maze[N][N], int i, int j)  //the isSafe function is usually found in backtracking
{  
    return ( i < N && j < N && maze[i][j] == 1); //valid input, and NOT blocked
} 

bool solveMazeRec( int maze[N][N], int i, int j, int sol[N][N]) //main code
{ 
    if ( i == N - 1 && j == N - 1 && maze[i][j] == 1) 
    { 
        sol[i][j] = 1; 
        return true; 
    } 
  
    if (isSafe(maze, i, j) == true) 
    { 
        sol[i][j] = 1; 
        if (solveMazeRec(maze, i + 1, j, sol) == true) 
            return true;   
        if (solveMazeRec(maze, i, j + 1, sol) == true) 
            return true; 
  
        sol[i][j] = 0; 
    } 
    return false; 
}

 
bool solveMaze(int maze[N][N]) 
{ 
    int sol[N][N] = { { 0, 0, 0, 0 }, 
                      { 0, 0, 0, 0 }, 
                      { 0, 0, 0, 0 }, 
                      { 0, 0, 0, 0 } }; 
    if (solveMazeRec(maze, 0, 0, sol) == false) 
    { 
        printf("Solution doesn't exist"); 
        return false; 
    } 
    printSolution(sol); 
    return true; 
} 

int main() {
	
	int maze[N][N] = { { 1, 0, 0, 0 }, //see closely....there are 2 possible paths, but our code will print only 1 path...since we are checking (i+1,j) before
                       { 1, 1, 0, 1 }, 
                       { 0, 1, 1, 0 }, 
                       { 1, 1, 1, 1 } }; 
    solveMaze(maze);    
    return 0;  
}
