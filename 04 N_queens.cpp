// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

// example
// Input: n = 4
// Output: [ [".Q..","...Q","Q...","..Q."] , ["..Q.","Q...","...Q",".Q.."] ]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above


#include <bits/stdc++.h>

using namespace std;
class Solution {
  public:
    bool isSafe1(int row, int col, vector < string > board, int n) 
    {
      // check upper element
      int duprow = row;
      int dupcol = col;

      while (row >= 0 && col >= 0)  //checking for diagonal
      {
        if (board[row][col] == 'Q')
          return false;
        row--;
        col--;
      }

      col = dupcol;
      row = duprow;
      while (col >= 0) 
      {
        if (board[row][col] == 'Q')
          return false;
        col--;
      }

      row = duprow;
      col = dupcol;
      while (row < n && col >= 0) 
      {
        if (board[row][col] == 'Q')
          return false;
        row++;
        col--;
      }
      return true;
    }

  public:
    void solve(int col, vector < string > & board, vector < vector < string >> & ans, int n) 
    {
      if (col == n) //if we have successfully reaches PAST the last column (since we have col==n , not n-1...thus past the last column)
      {
        ans.push_back(board);
        return;
      }
      for (int row = 0; row < n; row++)  //for each row in that column, check if we can place a queen
      {
        if (isSafe1(row, col, board, n)) //check if that position is safe
        {
          board[row][col] = 'Q';   //if safe,then backtrack!
          solve(col + 1, board, ans, n);  //move to the next column...since in each column, we are checking for a safe position to place a queen
          board[row][col] = '.'; //since backtracked
        }
      }
    }

  public:
    vector<vector<string>> solveNQueens(int n) 
    {
      vector<vector<string>> ans;  //this is the thing we want to return as our answer
      vector<string> board(n);
      string s(n, '.'); 
      for (int i = 0; i < n; i++) 
      {
        board[i] = s;//so basically board is a vector<string> with each element being a '.'
      }
      solve(0, board, ans, n);
      return ans;
    }
};
int main() {
  int n = 4; // we are taking 4*4 grid and 4 queens
  Solution obj;
  vector < vector < string >> ans = obj.solveNQueens(n);  //basically vector<vecotr<string>>ans is our answer which we wil print
  for (int i = 0; i < ans.size(); i++) 
  {
    cout << "Arrangement " << i + 1 << "\n"; 
    for (int j = 0; j < ans[0].size(); j++) 
    {
      cout << ans[i][j];
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
