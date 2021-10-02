Spiral Order Matrix II
Easy

35

9

Add to favorites
Asked In:
MICROSOFT
JP MORGAN
AMAZON
Given an integer A, generate a square matrix filled with elements from 1 to A2 in spiral order.



Input Format:

The first and the only argument contains an integer, A.
Output Format:

Return a 2-d matrix of size A x A satisfying the spiral order.
Constraints:

1 <= A <= 1000
Examples:

Input 1:
    A = 3

Output 1:
    [   [ 1, 2, 3 ],
        [ 8, 9, 4 ],
        [ 7, 6, 5 ]   ]

Input 2:
    4

Output 2:
    [   [1, 2, 3, 4],
        [12, 13, 14, 5],
        [11, 16, 15, 6],
        [10, 9, 8, 7]   ]



Solution ->
  
  o(n*n) time , o(1)space
  
  vector<vector<int> > Solution::generateMatrix(int A) {
    int j=1;
    vector<vector<int>>ans(A,vector<int>(A));
    int rowS=0,colS=0,rowE=A-1,colE=A-1;
    int k=0;
    while(rowS<=rowE && colS<=colE)
    {
        if(k==0)
        {
            //left to right
            for(int i=colS;i<=colE;i++)
            {
                ans[rowS][i]=j;
                j++;
            }
            rowS++;
        }

        else if(k==1)
        {
            //top to bottom
            for(int i=rowS;i<=rowE;i++)
            {
                ans[i][colE]=j;
                j++;
            }
            colE--;
        }

        else if(k==2)
        {
            //right to left
            for(int i=colE;i>=colS;i--)
            {
                ans[rowE][i]=j;
                j++;
            }
            rowE--;
        }

        else if(k==3)
        {
            for(int i=rowE;i>=rowS;i--)
            {
                ans[i][colS]=j;
                j++;
            }
            colS++;
        }
        k=(k+1)%4;
    }
    return ans;
}
