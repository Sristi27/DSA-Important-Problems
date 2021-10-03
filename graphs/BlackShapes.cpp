Black Shapes
Medium

24

3

Add to favorites
Asked In:
AMAZON
Given N x M character matrix A of O's and X's, where O = white, X = black.


Return the number of black shapes. A black shape consists of one or more adjacent X's (diagonals not included)




Input Format:

    The First and only argument is a N x M character matrix.
Output Format:

    Return a single integer denoting number of black shapes.
Constraints:

    1 <= N,M <= 1000
    A[i][j] = 'X' or 'O'
Example:

Input 1:
    A = [ OOOXOOO
          OOXXOXO
          OXOOOXO  ]
Output 1:
    3
Explanation:
    3 shapes are  :
    (i)    X
         X X
    (ii)
          X
    (iii)
          X
          X
Note: we are looking for connected shapes here.

XXX
XXX
XXX
is just one single connected black shape.
  
  
  
  Solution:


bool isSafe(int r,int c,vector<string>&mat)
{
    if(r<mat.size() && r>=0 && c<=mat[0].size() && c>=0) return true;
    return false;
}
void dfs(int r,int c,vector<string>&mat,vector<vector<int>>&vis)
{
    static int rdir[4]={-1,0,0,1};
    static int cdir[4]={0,-1,1,0};

    vis[r][c]=true;

    for(int k=0;k<4;k++)
    {
        int newr=r+rdir[k],newc=c+cdir[k];
        if(isSafe(newr,newc,mat) && !vis[newr][newc] && mat[newr][newc]=='X')
        dfs(newr,newc,mat,vis);
    }
}
int Solution::black(vector<string> &A) {
    int n=A.size(),m=A[0].size(); 
    int cnt=0;
    vector<vector<int>>vis(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j] && A[i][j]=='X')
            {
                dfs(i,j,A,vis);
                cnt++;
            }
        }
    }
    return cnt;

}
