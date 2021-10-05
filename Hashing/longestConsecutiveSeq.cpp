Longest Consecutive Sequence 
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Example: 

Given [100, 4, 200, 1, 3, 2],

The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
  
  
  int Solution::longestConsecutive(const vector<int> &A) {
    unordered_set<int>st;
    int ans=0;
    for(int i:A) st.insert(i);
    for(int i:A)
    {
        if(st.count(i-1)==0)
        {
            int cnt=1;
            int curr=i;
            while(st.count(curr+1)>0)
            {
                curr++;
                cnt++;
            }
            ans=max(cnt,ans);
        }
    }
    return ans;
}
