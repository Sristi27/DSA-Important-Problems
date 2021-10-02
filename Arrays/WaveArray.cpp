Wave Array  
Problem Description

Given an array of integers A, sort the array into a wave like array and return it, In other words, arrange the elements into a sequence such that 

a1 >= a2 <= a3 >= a4 <= a5.....
NOTE : If there are multiple answers possible, return the one that's lexicographically smallest.



Problem Constraints
1 <= len(A) <= 106

1 <= A[i] <= 106



Input Format
First argument is an integer array A.



Output Format
Return an array arranged in the sequence as described.



Example Input
Input 1:

A = [1, 2, 3, 4]
Input 2:

A = [1, 2]


Example Output
Output 1:

[2, 1, 4, 3]
Output 2:

[2, 1]


Example Explanation
Explanation 1:

One possible answer : [2, 1, 4, 3]
Another possible answer : [4, 1, 3, 2]
First answer is lexicographically smallest. So, return [2, 1, 4, 3].
Explanation 1:

Only possible answer is [2, 1].

Approach 1 -> Sort and swap adj elements 
(nlogn)
  
  vector<int> Solution::wave(vector<int> &A) {
    sort(A.begin(),A.end());
    int n=A.size();
    if(n==0 || n==1) return A;
    for(int i=0;i<n;i+=2)
    {
        swap(A[i],A[i+1]);
        if(i+2==n-1)
        break;
    }
    return A;
}


Approach 2 -> Traverse the even array elem and check if it is smaller than its adj,if it is swap them

vector<int> Solution::wave(vector<int> &A) { 
    int n=A.size();
    if(n==0 || n==1) return A;
    for(int i=0;i<n;i+=2)
    {
        if(i>0 && A[i]<A[i-1]) swap(&A[i],&A[i-1]);
        if(i<n-1 && A[i]<A[i+1]) swap(&A[i],&A[i+1]);
    }
    return A;
}
