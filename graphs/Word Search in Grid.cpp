Word Search Board
Hard 
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The cell itself does not count as an adjacent cell. 

The same letter cell may be used more than once.

Example :

Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns 1,
word = "SEE", -> returns 1,
word = "ABCB", -> returns 1,
word = "ABFSAB" -> returns 1
word = "ABCD" -> returns 0
Note that 1 corresponds to true, and 0 corresponds to false.


bool isSafe(int i,int j,vector<vector<char>>adj)
{
    if(i>=0 && i<adj.size() && j>=0 && j<adj[0].size()) return 1;
    return 0;
}
int dfs(int i,int j, vector<vector<char>>adj, string target,int index)
{
    static int rdir[4] = {-1,0,0,1};
    static int cdir[4] = {0,-1,1,0};

    if(index==target.size()-1) return 1;

    for(int k=0;k<4;k++)
    {
        int newi = i+rdir[k],newj=j+cdir[k];
        if(isSafe(newi,newj,adj) && adj[newi][newj]==target[index+1])
        {
            if(dfs(newi,newj,vis,adj,target,index+1)==1) 
            return 1;
        }
    }
    return 0;
}
int Solution::exist(vector<string> &A, string B) {
    int n=A.size();
    int m=A[0].size();
    int si,sj;
    vector<vector<char>>adj(n,vector<char>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        { 
            adj[i][j]=A[i][j];
        }
    } 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        { 
            if(adj[i][j]==B[0] && dfs(i,j,adj,B,0)) return 1;
        }
    }
    return 0;
}
