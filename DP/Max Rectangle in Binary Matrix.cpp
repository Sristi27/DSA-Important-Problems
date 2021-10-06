Given a 2D binary matrix filled with 0’s and 1’s, find the largest rectangle containing all ones and return its area.

Bonus if you can solve it in O(n^2) or less.

Example :

A : [  1 1 1
       0 1 1
       1 0 0 
    ]

Output : 4 

As the max area rectangle is created by the 2x2 rectangle created by (0,1), (0,2), (1,1) and (1,2)

  
  
  
  
  Solution 1 : Largest Rectangle in Histogram
  
  
  int findMax(vector<int>arr)
{
    int n=arr.size(),area=0,height,width;
    stack<int>st;
    for(int i=0;i<=n;i++)
    {
        while(!st.empty() && (i==n || arr[st.top()]>=arr[i]))
        {
            height=arr[st.top()];
            st.pop();
            if(st.empty()) width=i; 
            else width=i-st.top()-1;
            area=max(area,width*height);
        }
        st.push(i);
    }
    return area;
}
int Solution::maximalRectangle(vector<vector<int> > &A) {
    int r=A.size(),c=A[0].size(),area=findMax(A[0]);
    for(int i=1;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(A[i][j]==1) 
            A[i][j]+= A[i-1][j];
        }
        area=max(area,findMax(A[i]));
    }
    return area;
}


Solution 2: Dp approach 

int Solution::maximalRectangle(vector<vector<int> > &A) {
int dp[r][c];

    for(int i=0;i<r;i++) dp[i][0]=A[i][0];
    for(int i=0;i<c;i++) dp[0][i]=A[0][i];

    for(int i=1;i<r;i++)
    {
        for(int j=1;j<c;j++)
        {
            if(A[i][j]==1)
            dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
            else
            dp[i][j]=0;
        }
    }

    int s=dp[0][0],v;
    int area=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(s<dp[i][j])
            {
                s=dp[i][j];
                area=max(area,(i-s)*(j-s));
            }
        }
    }

    return area;
    }
