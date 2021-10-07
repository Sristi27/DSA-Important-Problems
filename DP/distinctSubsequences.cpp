Given two sequences A, B, count number of unique ways in sequence A, to form a subsequence that is identical to the sequence B.

Subsequence : A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, “ACE” is a subsequence of “ABCDE” while “AEC” is not).

Input Format:

The first argument of input contains a string, A.
The second argument of input contains a string, B.
Output Format:

Return an integer representing the answer as described in the problem statement.
Constraints:

1 <= length(A), length(B) <= 700
Example :

Input 1:
    A = "abc"
    B = "abc"
    
Output 1:
    1

Explanation 1:
    Both the strings are equal.

Input 2:
    A = "rabbbit" 
    B = "rabbit"

Output 2:
    3

Explanation 2:
    These are the possible removals of characters:
        => A = "ra_bbit" 
        => A = "rab_bit" 
        => A = "rabb_it"
        
    Note: "_" marks the removed character.
      
      
      
    vector<vector<int>>dp;
int rec(string a,int i,string b,int j)
{
    if(j==b.size()) return 1;
    if(i==a.size()) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(a[i]==b[j])
    return dp[i][j]=rec(a,i+1,b,j+1) + rec(a,i+1,b,j);
    return dp[i][j]=rec(a,i+1,b,j);
    
}
int Solution::numDistinct(string A, string B) {
    dp.clear();
    dp.resize(A.size(),vector<int>(B.size(),-1));
    return  rec(A,0,B,0);
}


Solution 2 -> DP


int numDistinct(string A, string B) {
        int n=A.size(),m=B.size();
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        for(int j=0;j<n;j++) dp[j][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=min(m,i);j++)
            {
                 if(A[i-1]==B[j-1])
                {
                    dp[i][j]=(dp[i-1][j] + dp[i-1][j-1]) %mod;
                }
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
    return dp[n][m];
 } 
};

