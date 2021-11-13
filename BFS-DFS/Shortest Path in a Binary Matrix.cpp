1091. Shortest Path in Binary Matrix
Medium

1782

98

Add to List

Share
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.

 

Example 1:


Input: grid = [[0,1],[1,0]]
Output: 2
Example 2:


Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4
Example 3:

Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1
  
  

  
 USE BFS
  Solution:

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;
        
        int row=grid.size();
        int xrow[8]={-1,-1,-1,0,0,1,1,1};
        int yrow[8]={-1,0,1,-1,1,-1,0,1};
        
         vector<vector<int>>mat(row,vector<int>(row,0));
         mat=grid;
         mat[0][0]=1;
        
        queue<pair<int,int>>q;
        q.push({0,0}); 
        while(!q.empty())
        {
            pair<int,int>p=q.front();
            q.pop();
            int x=p.first,y=p.second;
            if(x==row-1 && y==row-1) return mat[x][y];
            for(int i=0;i<8;i++)
            {
                int newx=x+xrow[i],newy=y+yrow[i];
                if(newx<row && newy<row && newx>=0 && newy>=0 &&
                   mat[newx][newy]==0)
                {
                    q.push({newx,newy});
                    mat[newx][newy]=mat[x][y]+1; 
                } 
            }
        }
        return -1;
    }
};
