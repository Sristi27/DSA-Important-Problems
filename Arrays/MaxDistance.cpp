Max Distance
Medium 
Problem Description

Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].



Input Format
First and only argument is an integer array A.



Output Format
Return an integer denoting the maximum value of j - i;



Example Input
Input 1:

 A = [3, 5, 4, 2]


Example Output
Output 1:

 2


Example Explanation
Explanation 1:

 Maximum value occurs for pair (3, 4).

   
   
   approach -> keep track of max elements to the right
   
   int Solution::maximumGap(const vector<int> &A) {
    int n=A.size();
    int maxfromend[n];
    maxfromend[n-1]=A[n-1];
    for(int i=n-2;i>=0;i--)
    maxfromend[i]=max(maxfromend[i+1],A[i]);
    int ans=INT_MIN;
    for(int i=0,j=0;i<n && j<n;)
    {
        if(A[i]<=maxfromend[j])
        {
            ans=max(ans,j-i);
            j++;
        }
        else
        {
            i++;
        }
    }
    return ans;
}

o(n)->time and space

