// Rules:
// 1. say we have n*n grid, then numbers should be from [1 , n]
// 2. all rows should hv diff numbers
// 3. all columns should hv diff numbers
// 4. every subgrid of size sqrt(n) must have diff numbers

//Note: 0 in the cell means the cell is empty

// example :
// input = { {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
//          {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
//          {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
//          {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
//          {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
//          {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
//          {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
//          {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
//          {0, 0, 5, 2, 0, 6, 3, 0, 0} }
// Output:
//           3 1 6 5 7 8 4 9 2
//           5 2 9 1 3 4 7 6 8
//           4 8 7 6 2 9 5 3 1
//           2 6 3 4 1 5 9 8 7
//           9 7 4 8 6 3 1 2 5
//           8 5 1 7 9 2 6 4 3
//           1 3 8 9 4 7 2 5 6
//           6 9 2 3 5 1 8 7 4
//           7 4 5 2 8 6 3 1 9
// Explanation: Each row, column and 3*3 box of the output matrix contains unique numbers.


#include <bits/stdc++.h> 
using namespace std; 
#define N 9 

bool isSafe(int board[N][N],int row, int col, int num) 
{ 
	for (int d = 0; d < N; d++)  //check if num is already present in the same column
	{ 
	    if (board[row][d] == num) 
		return false; 
	} 

	for (int r = 0; r < N; r++)  //check if num is already present in the same column
	{ 
	    if (board[r][col] == num)  
		return false; 
	}  
	int s = (int)sqrt(N); 
	int boxRowStart = row - row % s; //IMP...sratring indices for the boxes in sudoku
	int boxColStart = col - col % s; //IMP

	for (int r = boxRowStart; r < boxRowStart + s; r++)   // check if the num does NOT exist in the bos
	{ 
	    for (int d = boxColStart; d < boxColStart + s; d++)  
	    { 
		if (board[r][d] == num)  
		    return false; 
	    } 
	} 
	return true; 
} 

bool solve(int board[N][N],int n) 
{ 
	int row = -1; 
        int col = -1; 
        bool isEmpty = true; //to check if the sudoku is filled or not
        for (int i = 0; i < n; i++)  
        { 
            for (int j = 0; j < n; j++)  
            { 
                if (board[i][j] == 0)  
                { 
                    row = i; //row for the empty cell we encounter
                    col = j; //column for the empty cell we encounter
                    isEmpty = false; 
                    break; 
                } 
            } 
            if (!isEmpty)
                break; 
        } 
  
        if (isEmpty)  //since sudoku was filled
            return true; 
        
        for (int num = 1; num <= n; num++)  //IMP....the numbers we fill must be bw [1,n]
        { 
            if (isSafe(board, row, col, num))  //if safe
            { 
                board[row][col] = num; //then update the empty cell
                if (solve(board, n))  
                    return true; //if sudoku gets filled
                else 
                    board[row][col] = 0; //backtrack
            } 
        } 
        return false; 
} 

void printGrid(int grid[N][N]) 
{ 
	for (int row = 0; row < N; row++) 
	{ 
		for (int col = 0; col < N; col++) 
			cout << grid[row][col] << " "; 
		cout << endl; 
	} 
} 
 

int main() 
{ 
	int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 }, 
				{ 5, 2, 0, 0, 0, 0, 0, 0, 0 }, 
				{ 0, 8, 7, 0, 0, 0, 0, 3, 1 }, 
				{ 0, 0, 3, 0, 1, 0, 0, 8, 0 }, 
				{ 9, 0, 0, 8, 6, 3, 0, 0, 5 }, 
				{ 0, 5, 0, 0, 9, 0, 6, 0, 0 }, 
				{ 1, 3, 0, 0, 0, 0, 2, 5, 0 }, 
				{ 0, 0, 0, 0, 0, 0, 0, 7, 4 }, 
				{ 0, 0, 5, 2, 0, 6, 3, 0, 0 } }; 
	if (solve(grid,N) == true) 
		printGrid(grid); 
	else
		cout << "No solution exists"; 

	return 0; 
} 

