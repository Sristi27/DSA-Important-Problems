Problem Description

Given a binary matrix A of size N x M.

 Cells which contain 1 are called filled cell and cell that contain 0 are called empty cell.

Two cells are said to be connected if they are adjacent to each other horizontally, vertically, or diagonally.

If one or more filled cells are also connected, they form a region. Find the length of the largest region.



Problem Constraints
 1 <= N, M <= 102

 A[i][j]=0 or A[i][j]=1



Input Format
First argument is a 2D binary matrix Aof size  N x M.



Output Format
Return a single interger denoting the length of largest region.



Example Input
Input 1:

 A = [  [0, 0, 1, 1, 0]
        [1, 0, 1, 1, 0]
        [0, 1, 0, 0, 0]
        [0, 0, 0, 0, 1]
    ]
Input 2:

 A = [  [1, 1, 1]
        [0, 0, 1]
    ]


Example Output
Output 1:

 6
Output 2:

 4


Example Explanation
Explanation 1:

 The largest region is denoted by red color in the matrix:
    00110
    10110
    01000
    00001
Explanation 2:

 The largest region is:
    111
    001

      
      
      
      
      
      
      void dfs(int i,int j,vector<vector<int>>&A,int &count)
{
    count++;
    static int rdir[8]={-1,-1,-1,0,0,1,1,1},cdir[8]={-1,0,1,-1,1,-1,0,1};
    A[i][j]=0; //vis
    for(int k=0;k<8;k++)
    {
        if(i+rdir[k]>=0 && i+rdir[k]<A.size() && j+cdir[k]>=0 && j+cdir[k]<A[0].size())
        {
            int newx=i+rdir[k];
            int newy=j+cdir[k];
            if(A[newx][newy]==1)
             dfs(newx,newy,A,count);
        }
    }
}
int Solution::solve(vector<vector<int> > &A) 
{
    int n=A.size(),m=A[0].size(),maxc=INT_MIN; 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(A[i][j]==1)
            {
                int count=0;
                dfs(i,j,A,count);
                maxc=max(maxc,count);
            }
        }
    }
    return maxc;
}


o(n*m) time complexity -> n*m*8 directoins differnetky
