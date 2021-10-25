Rain Water Trapped
Hard

126

4

Add to favorites
Asked In:
QUALCOMM
AMAZON
MICROSOFT
GOLDMAN SACHS
Problem Description

Given an integer array A of non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.



Problem Constraints
1 <= |A| <= 100000



Input Format
The only argument given is integer array A.



Output Format
Return the total water it is able to trap after raining.



Example Input
Input 1:

 A = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
Input 2:

 A = [1, 2]


Example Output
Output 1:

 6
Output 2:

 0


Example Explanation
Explanation 1:

 
 In this case, 6 units of rain water (blue section) are being trapped.
Explanation 2:

 No water is trapped.


   
   
   int Solution::trap(const vector<int> &A) {
    int i=0,j=A.size()-1;
    int leftMax=0,rightMax=0;
    int res=0;
    while(i<=j)
    {
        if(A[i]<=A[j]) //this will be my height then
        {
            if(A[i]>leftMax)
            leftMax=A[i];
            else
            {
                res+=leftMax-A[i];
                i++;
            }
        }
        else
        {
            if(A[j]>rightMax)
            rightMax=A[j];
            else
            {
                res+=rightMax-A[j];
                j--;
            }

        }   
    }
    return res;
}
