You are given a set of coins S. In how many ways can you make sum N assuming you have infinite amount of each coin in the set.

Note : Coins in set S will be unique. Expected space complexity of this problem is O(N).

Example :

Input : 
	S = [1, 2, 3] 
	N = 4

Return : 4

Explanation : The 4 possible ways are
{1, 1, 1, 1}
{1, 1, 2}
{2, 2}
{1, 3}	
Note that the answer can overflow. So, give us the answer % 1000007
  
  
  
  //Time complexity -> o(nb) , Space complexity = o(b)
  int Solution::coinchange2(vector<int> &A, int B) {
    int mod=1000007;
    int n=A.size();
    int dp[B+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=B;j++)
      {
          if(A[i-1]<=j)
          dp[j] = (dp[j-A[i-1]]%mod + dp[j]%mod)%mod;
          else
          dp[j]= dp[j]%mod;
      }   
    }    
    return dp[B]%mod;
}

Space comp = o(nm)
  
  int Solution::coinchange2(vector<int> &A, int B) {
    int mod=1000007;
    int n=A.size();
    int dp[n+1][B+1];
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    //when sum =0,first column
    for(int i=0;i<=n;i++)
    dp[i][0]=1;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=B;j++)
      {
          if(A[i-1]<=j)
          dp[i][j] = (dp[i][j-A[i-1]]%mod + dp[i-1][j]%mod)%mod;
          else
          dp[i][j]= dp[i-1][j]%mod;
      }   
    }    
    return dp[n][B]%mod;
}
 
