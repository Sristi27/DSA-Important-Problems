Implement wildcard pattern matching with support for ‘?’ and ‘*’ for strings A and B.

’?’ : Matches any single character.
‘*’ : Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Input Format:

The first argument of input contains a string A.
The second argument of input contains a string B.
Output Format:

Return 0 or 1:
    => 0 : If the patterns do not match.
    => 1 : If the patterns match.
Constraints:

1 <= length(A), length(B) <= 9e4
Examples :

Input 1:
    A = "aa"
    B = "a"

Output 1:
    0

Input 2:
    A = "aa"
    B = "aa"

Output 2:
    1

Input 3:
    A = "aaa"
    B = "aa"

Output 3:
    0
    
Input 4:
    A = "aa"
    B = "*"

Output 4:
    1

Input 5:
    A = "aa"
    B = "a*"

Output 5:
    1

Input 6:
    A = "ab"
    B = "?*"

Output 6:
    1

Input 7:
    A = "aab"
    B = "c*a*b"

Output 7:
    0
      
      
      int Solution::isMatch(const string A, const string B) {
    int n=A.size(),m=B.size();
    bool dp[n+1][m+1];
    memset(dp,false,sizeof(dp));
    //empty pat and empty string
    dp[0][0]=true;
    for(int i=1;i<=m;i++)
    {
        if(B[i-1]=='*')
        dp[0][i]=dp[0][i-1];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
             if(B[i-1]=='*')
             {
                 dp[i][j]=dp[i-1][j] || dp[i][j-1];
             }
             else if(B[i-1]=='?' || (A[i-1]==B[j-1]))
             {
                 dp[i][j]=dp[i-1][j-1];
             }
        }
    }
    return dp[n][m];
}
