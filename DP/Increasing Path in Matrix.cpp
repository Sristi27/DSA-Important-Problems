Increasing Path in Matrix
Medium

22

100

Add to favorites
Asked In:
GOOGLE
Problem Description

Given a 2D integer matrix A of size N x M.

From A[i][j] you can move to A[i+1][j], if A[i+1][j] > A[i][j], or can move to A[i][j+1] if A[i][j+1] > A[i][j].

The task is to find and output the longest path length if we start from (0, 0).

NOTE:

If there doesn't exist a path return -1.


Problem Constraints
1 <= N, M <= 103

1 <= A[i][j] <= 108



Input Format
First and only argument is an 2D integer matrix A of size N x M.



Output Format
Return a single integer denoting the length of longest path in the matrix if no such path exists return -1.



Example Input
Input 1:

 A = [  [1, 2]
        [3, 4]
     ]
Input 2:

 A = [  [1, 2, 3, 4]
        [2, 2, 3, 4]
        [3, 2, 3, 4]
        [4, 5, 6, 7]
     ]


Example Output
Output 1:

 3
Output 2:

 7


Example Explanation
Explanation 1:

 Longest path is either 1 2 4 or 1 3 4.
Explanation 2:

 Longest path is 1 2 3 4 5 6 7.


   
   int Solution::solve(vector<vector<int> > &A) {
    int n=A.size(),m=A[0].size();
    int dp[n][m];
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    int res=-1;
    for(int i=1;i<n;i++)
    {
        if(A[i-1][0]< A[i][0] && dp[i-1][0]!=-1)
        dp[i][0] = 1+dp[i-1][0];
        else
        dp[i][0]=-1;
        res=max(res,dp[i][0]);
    }
    for(int i=1;i<m;i++)
    {
        if(A[0][i-1] < A[0][i] && dp[0][i-1]!=-1)
        dp[0][i] = 1+dp[0][i-1];
        else
        dp[0][i]=-1;
        res=max(res,dp[0][i]);
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(A[i-1][j] < A[i][j] && dp[i-1][j]!=-1)
            dp[i][j]=1+dp[i-1][j];

            else if(A[i][j] > A[i][j-1] && dp[i][j-1]!=-1)
            dp[i][j]=1+dp[i][j-1];
            
            else
            dp[i][j]=-1;
            
            res=max(res,dp[i][j]);
        }
    }
    return dp[n-1][m-1];
} 
