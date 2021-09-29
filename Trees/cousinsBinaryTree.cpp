Cousins in Binary Tree
Medium

50

10

Add to favorites
Asked In:
AMAZON
DE SHAW
Problem Description

Given a Binary Tree A consisting of N nodes.

You need to find all the cousins of node B.

NOTE:

Siblings should not be considered as cousins.
Try to do it in single traversal.
You can assume that Node B is there in the tree A.
Order doesn't matter in the output.


Problem Constraints
 1 <= N <= 105 

 1 <= B <= N



Input Format
First Argument represents the root of binary tree A.

Second Argument is an integer B denoting the node number.



Output Format
Return an integer array denoting the cousins of node B.

NOTE: Order doesn't matter.



Example Input
Input 1:

 A =

           1
         /   \
        2     3
       / \   / \
      4   5 6   7 


B = 5

Input 2:

 A = 
            1
          /   \
         2     3
        / \ .   \
       4   5 .   6


B = 1




Example Output
Output 1:

 [6, 7]
Output 2:

 []


Example Explanation
Explanation 1:

 Cousins of Node 5 are Node 6 and 7 so we will return [6, 7]
 Remember Node 4 is sibling of Node 5 and do not need to return this.
Explanation 2:

 Since Node 1 is the root so it doesn't have any cousin so we will return an empty array.
   
   /**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// pair<child,parent>
//level order traversal
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int>ans;
    if(!A || A->val==B)
    return ans;
    //find parent of given TreeNode
    queue<TreeNode*>q;
    q.push(A);
    bool found=false;
    while(!q.empty() && !found)
    {
        int c=q.size();
        while(c--)
        {
            TreeNode*temp=q.front();
            q.pop();
            if((temp->left && temp->left->val==B) || (temp->right && temp->right->val==B))
            found=true;
            else
            {   
                if(temp->left)
                q.push(temp->left);
                if(temp->right)
                q.push(temp->right);
            }
        }
    }
    while(!q.empty())
    {
        ans.push_back(q.front()->val);
        q.pop();
    }
    return ans;
}

