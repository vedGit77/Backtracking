// Rules:
// 1. say we have n*n grid, then numbers should be from [1 , n]
// 2. all rows should hv diff numbers
// 3. all columns should hv diff numbers
// 4. every subgrid of size sqrt(n) must have diff numbers

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



