Jump Game II
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
 

Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 105
  
  
  
  
  
  
  
  
  
  
C++	
1
class Solution {
2
public:
3
    int jump(vector<int>& nums) {
4
        
5
        int n=nums.size();
6
        vector<int>minDp(n,INT_MAX);
7
        minDp[0]=0;
8
        for(int i=1;i<n;i++)
9
        {
10
            for(int j=0;j<i;j++)
11
            {
12
                if(j+nums[j]>=i)
13
                {
14
                    minDp[i]=min(minDp[i],minDp[j]+1);
15
                }
16
            }
17
        }
18
        return minDp[n-1];
19
    }
20
};
