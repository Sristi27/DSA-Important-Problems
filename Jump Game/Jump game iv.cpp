1345. Jump Game IV
Hard
Given an array of integers arr, you are initially positioned at the first index of the array.

In one step you can jump from index i to index:

i + 1 where: i + 1 < arr.length.
i - 1 where: i - 1 >= 0.
j where: arr[i] == arr[j] and i != j.
Return the minimum number of steps to reach the last index of the array.

Notice that you can not jump outside of the array at any time.

 

Example 1:

Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
Output: 3
Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.
Example 2:

Input: arr = [7]
Output: 0
Explanation: Start index is the last index. You don't need to jump.
Example 3:

Input: arr = [7,6,9,6,9,6,9,7]
Output: 1
Explanation: You can jump directly from index 0 to index 7 which is last index of the array.
Example 4:

Input: arr = [6,1,9]
Output: 2
Example 5:

Input: arr = [11,22,7,7,7,7,7,7,7,22,13]
Output: 3
 

Constraints:

1 <= arr.length <= 5 * 104
-108 <= arr[i] <= 108
  
  
  
  
  
 SOLUTION
 
 class Solution {
public:
    int minJumps(vector<int>& arr) {
        
        int n=arr.size();
        vector<int>dp(n,INT_MAX);
        //bfs
        vector<bool>visited(n,false);
        unordered_map<int,vector<int>>graph;
        
        //same value nodes
        for(int i=1;i<n;i++)
        {
            graph[arr[i]].push_back(i);
        }
        // 1->2 
        // 5->6->7 
        queue<vector<int>>todo;
        todo.push({0,0}); //indices no-of-steps //0 1 ,1 2
        visited[0]=true;
        
        while(!todo.empty())
        {
            vector<int>curr=todo.front();
            todo.pop();
            if(curr[0]==n-1)
            {
                return curr[1];
            }
            int right=curr[0]+1;
            if(right<n && visited[right]==false)
            {
                todo.push({right,curr[1]+1});
                visited[right]=true;
            }
            int left=curr[0]-1;
            if(left>=0 && visited[left]==false)
            {
                todo.push({left,curr[1]+1});
                visited[left]=true;
            }
            for(int i:graph[arr[curr[0]]])
            {
                cout<<i;
                if(!visited[i])
                {
                    todo.push({i,curr[1]+1});
                    visited[i]=true;
                }
            }
            cout<<endl;
            graph.erase(arr[curr[0]]);
           }
           return n-1;
      
    }
};
