Interleaving Strings
Hard 
Given A, B, C, find whether C is formed by the interleaving of A and B.

Input Format:*

The first argument of input contains a string, A.
The second argument of input contains a string, B.
The third argument of input contains a string, C.
Output Format:

Return an integer, 0 or 1:
    => 0 : False
    => 1 : True
Constraints:

1 <= length(A), length(B), length(C) <= 150
Examples:

Input 1:
    A = "aabcc"
    B = "dbbca"
    C = "aadbbcbcac"

Output 1:
    1
    
Explanation 1:
    "aa" (from A) + "dbbc" (from B) + "bc" (from A) + "a" (from B) + "c" (from A)

Input 2:
    A = "aabcc"
    B = "dbbca"
    C = "aadbbbaccc"

Output 2:
    0

Explanation 2:
    It is not possible to get C by interleaving A and B.
      
      
      
      
   Solution 1:

Recursion Aproach :-
  
  bool isInterleaved(
    char* A, char* B, char* C)
{
    // Base Case: If all strings are empty
    if (!(*A || *B || *C))
        return true;
 
    // If C is empty and any of the
    // two strings is not empty
    if (*C == '\0')
        return false;
 
    // If any of the above mentioned
    // two possibilities is true,
    // then return true, otherwise false
    return ((*C == *A) && isInterleaved(
                              A + 1, B, C + 1))
           || ((*C == *B) && isInterleaved(
                                 A, B + 1, C + 1));
}




DP approach :-
  
  int Solution::isInterleave(string A, string B, string C) {
    int n=A.size(),m=B.size();
    if(n+m != C.size()) return 0;
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(j==0 && i!=0)
            {
                if(A[i-1]==C[i-1]) dp[i][j]=true;
            }
            else if(i==0 && j!=0)
            {
                if(B[j-1]==C[j-1]) dp[i][j]=true;
            }
            else 
            {
                char x = A[i-1];
                char y = B[j-1];
                char z = C[i+j-1];
                if(x==y && y==z) 
                dp[i][j]=dp[i-1][j] || dp[i][j-1];
                else if(x==z)
                {
                    dp[i][j]=dp[i-1][j];
                }
                else if(y==z)
                {
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
    }
    return dp[n][m];
}
