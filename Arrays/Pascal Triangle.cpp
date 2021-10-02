Pascal Triangle 

Given numRows, generate the first numRows of Pascal's triangle.
Pascal's triangle : To generate A[C] in row R, sum up A'[C] and A'[C-1] from previous row R - 1.

Example:

Given numRows = 5,

Return

[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
]


vector<vector<int> > Solution::solve(int A) {
    vector<vector<int>>ans;
    for(int i=1;i<=A;i++)
    {
        vector<int>temp(i);
        temp[0]=1;
        temp[i-1]=1;
        if(i>=3 && ans.size()!=0)
        { 
            int j=1; 
            while(j<i-1)
            {
                temp[j]=ans[i-2][j-1]+ans[i-2][j];
                j++;
            }
        }
        ans.push_back(temp);
    }
    //o(n^2)
    return ans;
}





Approach 2:
C(line, i)   = line! / ( (line-i)! * i! )
C(line, i-1) = line! / ( (line - i + 1)! * (i-1)! )
We can derive following expression from above two expressions.
C(line, i) = C(line, i-1) * (line - i + 1) / i

So C(line, i) can be calculated from C(line, i-1) in O(1) time


  for(int i=1;i<=A;i++)
    {
        int f=1;
        vector<int>temp(i);
        for(int j=1;j<=i;j++)
        {
            temp[j-1]=f;
            f=f*(i-j)/j;
        }
        ans.push_back(temp);
    }
    return ans;
}
