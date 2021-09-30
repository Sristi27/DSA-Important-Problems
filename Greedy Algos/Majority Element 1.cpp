Majority Element 
AMAZON
Problem Description

Given an array of size n, find the majority element. The majority element is the element that appears more than floor(n/2) times.
You may assume that the array is non-empty and the majority element always exist in the array.

Example :

Input : [2, 1, 2]
Return  : 2 which occurs 2 times which is greater than 3/2.
  
  
  
  int Solution::majorityElement(const vector<int> &A) {
    int n=A.size();
    int cnt1=0,ele;
    int i=0;
    while(i<n)
    {
        if(cnt1==0)
        {
            ele=A[i];
            cnt1=1;
        }
        else if(A[i]==ele)
        cnt1++; 
        else 
        cnt1--;
        i++;
    }
    return ele;
}
