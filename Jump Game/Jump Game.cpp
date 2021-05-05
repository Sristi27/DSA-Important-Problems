
55. Jump Game
Medium

6257

424

Add to List

Share
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 3 * 104
0 <= nums[i] <= 105
  
  
  
  
 Solution:

class Solution {
public:
    bool canJump(vector<int>& A) {
      
      
    Soluiton A
    //     int n=A.size();
    // int dp[n];
    // dp[n-1]=0;
    // for(int i=n-2;i>=0;i--){
    //     if(i+A[i]>n-1) {
    //         dp[i]=n-1;
    //         continue;
    //     }
    //     dp[i]=i+A[i];
    //     for(int j=i+1;j<=i+A[i];j++)
    //      dp[i]=max(dp[i],dp[j]);
    // }
    // if(dp[0]==n-1)
    //  return true;
    // else return false;
        
      
      Solution B
        //at each index find max reachable from that curr idx
        int n=A.size(),reach=0;
        for(int i=0;i<n;i++)
        {
            if(reach<i) return false;
            reach=max(reach,i+A[i]);
        }
        
        return true;
}
};
