994. Rotting Oranges 
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.
  
  
  
  class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>oranges;
        int count=0;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                    oranges.push({i,j});
                if(grid[i][j]==1)
                    count++;
            }
        }
        int time=0;
        int xrow[4]={-1,0,0,1},yrow[4]={0,-1,1,0};
        while(!oranges.empty() && count>0)
        {
            int c=oranges.size();
            while(c--)
            {
                pair<int,int>cell=oranges.front();
                oranges.pop();
                int x=cell.first,y=cell.second;
            
                for(int i=0;i<4;i++)
                {
                    int newx=x+xrow[i],newy=y+yrow[i];
                    if(newx>=0 && newx<n && newy>=0 && newy<m && grid[newx][newy]==1)
                    {
                        grid[newx][newy]=2;
                        count--;
                        oranges.push({newx,newy});
                    }

                }
            } 
            time++;
        }
        
        if(count==0) return time;
        else return -1;
    }
};
