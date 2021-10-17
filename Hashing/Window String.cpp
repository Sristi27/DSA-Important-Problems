Window String
Medium 
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in linear time complexity.

Note that when the count of a character C in T is N, then the count of C in minimum window in S should be at least N.

Example :

S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC"

Note:

If there is no such window in S that covers all characters in T, return the empty string ''.
If there are multiple such windows, return the first occurring minimum window ( with minimum start index ).
  
  
  string Solution::minWindow(string A, string B) {
    unordered_map<char,int>mp;
    for(char c:B) mp[c]++;
    int n=A.size();
    int dist=mp.size();
    int i=0,j=0;
    int res=INT_MAX,start;
    while(j<n)
    {
        mp[A[j]]--;
        if(mp[A[j]]==0)
        dist--;
        if(dist==0)
        {
            while(dist==0)
            {
                 if (res > j - i + 1) {
                    res = min(res, j - i + 1);
                    start = i;
                } 
                mp[A[i]]++;
                if(mp[A[i]]==1) 
                dist++;
                i++;
            }  
        }
        j++;
    }
    if(res==INT_MAX) return "";
    return A.substr(start,res);
}
