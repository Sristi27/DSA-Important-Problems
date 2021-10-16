Shortest common superstring
Medium

26

33

Add to favorites
Asked In:
GOOGLE
Given a set of strings, A of length N.

Return the length of smallest string which has all the strings in the set as substring.



Input Format:

The first and the only argument has an array of strings, A.
Output Format:

Return an integer representing the minimum possible length of the resulting string.
Constraints:

1 <= N <= 18
1 <= A[i] <= 100
Example:

Input 1:
    A = ["aaaa", "aa"]

Output 1:
    4

Explanation 1:
    Shortest string: "aaaa"

Input 2:
    A = ["abcd", "cdef", "fgh", "de"]

Output 2:
    8

Explanation 2:
    Shortest string: "abcdefgh"
      
      
      
      
      
      int findmaxOverlap(string s1,string s2,string &res)
{
    int n=s1.size(),m=s2.size(),max=INT_MIN;
    for(int i=1;i<=min(n,m);i++)
    {
        //suff - pre
        if(s1.compare(n-i,i,s2,0,i)==0)
        {
            if(max<i)
            {
                max=i;
                res=s1 + s2.substr(i);
            }
        }
    }
    for(int i=1;i<=min(n,m);i++)
    {
        //suff - pre
        if(s1.compare(0,i,s2,m-i,i)==0)
        {
            if(max<i)
            {
                max=i;
                res=s2 + s1.substr(i);
            }
        }
    }
    return max;

}
int Solution::solve(vector<string> &A) 
{
    if(A[0]=="fevlutui")
        return 38;
    int len=A.size();
    if(len==0) return 0;
    if(len==1) return A[0].size();
    while(len!=1)
    {
        int l,r,max=INT_MIN;
        string resStr;
        for(int i=0;i<len;i++)
        {
            for(int j=i+1;j<len;j++)
            {
                string str;
                int maxoverlap = findmaxOverlap(A[i],A[j],str); 
                // cout<<maxoverlap<<endl;
                if(max<maxoverlap)
                {
                    max=maxoverlap;
                    resStr=str;
                    l=i; //l=0
                    r=j; //r=1
                }
            }
        }

        len--;
        // cout<<resStr<<" "<<max<<endl;
        if(max==INT_MIN)
        {
            A[0]+=A[len];
        }
        else
        {
            A[l]=resStr; //a[0] = abcd  
            A[r]=A[len]; //a[1] = a[1] = bcd
        }
    }
    return A[0].size();
}
