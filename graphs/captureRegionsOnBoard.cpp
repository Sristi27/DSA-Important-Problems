Capture Regions on Board 
Problem Description

Given a 2D character matrix A of size N x M, containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.



Problem Constraints
1 <= N, M <= 103



Input Format
First and only argument 2D character matrix A of size N X M.



Output Format
Make changes to the the input only as matrix is passed by reference.



Example Input
Input 1:

 A = [  [X, X, X, X],
        [X, O, O, X],
        [X, X, O, X],
        [X, O, X, X]
     ]


Example Output
Output 1:

 A = [  [X, X, X, X],
        [X, X, X, X],
        [X, X, X, X],
        [X, O, X, X]
     ]


Example Explanation
Explanation 1:

 'O' in (4,2) is not surrounded by X from below.


   void dfs(int x,int y,vector<vector<char>>&vis)
{
    static int rdir[4]={-1,0,0,1},cdir[4]={0,-1,1,0};
    for(int k=0;k<4;k++)
    {
        int newx=x+rdir[k];
        int newy=y+cdir[k];
        if(newx>=0 && newx<vis.size() && newy>=0 && newy<vis[0].size())
        {
            if(vis[newx][newy]=='O')
            {
                vis[newx][newy]='N';
                dfs(newx,newy,vis);
            }
        }
    }
}
void Solution::solve(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<char>>vis(A.begin(),A.end());
    int n=A.size(),m=A[0].size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if((i==0 || i==n-1 || j==0 || j==m-1) && A[i][j]=='O')
            {
                // cout<<i<<" "<<j<<endl;
                vis[i][j]='N';
                dfs(i,j,vis);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(vis[i][j]=='O')
            vis[i][j]='X';
            else if(vis[i][j]=='N')
            vis[i][j]='O';
        }
    }
    A=vis;
}
