// Consider a rat placed at (0, 0) in a square matrix of order N * N. 
// It has to reach the destination at (N - 1, N - 1). 
// Find all possible paths that the rat can take to reach from source to destination. 
// The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). 
// Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it  
// value 1 at a cell in the matrix represents that rat can be travel through it

// Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.


// example
// Input:
// N = 4
// m[][] = {{1, 0, 0, 0},
//          {1, 1, 0, 1}, 
//          {1, 1, 0, 0},
//          {0, 1, 1, 1}}
// Output:
// DDRDRR DRDDRR


class Solution{
   public:
   void findPath(vector<vector<int>> &m,int i,int j,int n,string asf,vector<string>&ans, vector<vector<bool>>&visited)
   {
       if(i<0||j<0||i>=n||j>=n||visited[i][j]==true||m[i][j]==0) // check if valid index or not
         return ; 
       if(i==n-1&&j==n-1)
       {
           ans.push_back(asf);
       }
       visited[i][j]=true; //visited use karna is IMP....say if we travel downwards, then the upper cell MUST be labelled true...otherwise we will always travel upwards again...runtime error
       findPath(m,i+1,j,n,asf+'D',ans,visited); //we did asf+'D'...NOT asf+='D'....SUPER IMP...asf not updated....since after function is over, we get the asf without the added 'D' at last
       findPath(m,i,j+1,n,asf+'R',ans,visited);
       findPath(m,i-1,j,n,asf+'U',ans,visited);
       findPath(m,i,j-1,n,asf+'L',ans,visited);
       visited[i][j]=false;
   }
   vector<string> findPath(vector<vector<int>> &m, int n) {
       vector<string>ans;
       vector<vector<bool>> visited(n,vector<bool>(n,false));
       string asf;
       findPath(m,0,0,n,asf,ans,visited);
       return ans;
   }
};


//a noob way of writing the same code....which i wrote is below


class Solution{
    public:
    bool isValid(int i, int j, int n,vector<vector<int>> &m, vector<vector<bool>>&visited)
    {
        if(i>=n || j>=n ||i<0 ||j<0 || m[i][j]==0 || visited[i][j]==true)
            return false;
        return true;
    }
    void fun(int i, int j,int n,vector<string>&ans, string& s,vector<vector<int>> &m,vector<vector<bool>>&visited)
    {
        if(i==(n-1) && j==(n-1) && isValid(i,j,n,m,visited))
        {
            ans.push_back(s);
        }
        
        if(m[i][j]==0)
            return;
            
        if(isValid(i+1,j,n,m,visited))
        {
            s.push_back('D');
            visited[i][j]=true;
            fun(i+1,j,n,ans,s,m,visited);
            visited[i][j]=false;
            s.pop_back();
        }
        if(isValid(i,j+1,n,m,visited))
        {
            s.push_back('R');
            visited[i][j]=true;
            fun(i,j+1,n,ans,s,m,visited);
            visited[i][j]=false;
            s.pop_back();
        }
        if(isValid(i-1,j,n,m,visited))
        {
            s.push_back('U');
            visited[i][j]=true;
            fun(i-1,j,n,ans,s,m,visited);
            visited[i][j]=false;
            s.pop_back();
        }
        if(isValid(i,j-1,n,m,visited))
        {
            s.push_back('L');
            visited[i][j]=true;
            fun(i,j-1,n,ans,s,m,visited);
            visited[i][j]=false;
            s.pop_back();
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>ans;
        string s;
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        
        int i=0,j=0;
        visited[0][0]=true;
        fun(i,j,n,ans,s,m,visited);
        return ans;
    }
};

    

