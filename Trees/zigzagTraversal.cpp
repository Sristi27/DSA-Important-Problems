ZigZag Level Order Traversal BT
 
Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left to right, then right to left for the next level and alternate between).

Example : 

Given binary tree

    3
   / \
  9  20
    /  \
   15   7
  
  
return

[
         [3],
         [20, 9],
         [15, 7]
]

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* root) {
    bool flag=true;
    queue<TreeNode*>q;
    q.push(root);
    vector<vector<int>>ans;
    while(!q.empty())
    {
        int size=q.size();
        vector<int>curr;
        while(size--)
        {
            TreeNode* topnode = q.front();
            curr.push_back(topnode->val);
            q.pop();
            if(topnode->left)
            q.push(topnode->left);
            if(topnode->right)
            q.push(topnode->right);
        }
        if(flag)
        ans.push_back(curr);
        else
        {
            reverse(curr.begin(),curr.end());
            ans.push_back(curr);
        }
        flag=!flag;
    }
    return ans;
}
