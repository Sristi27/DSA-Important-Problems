Sum Root to Leaf Numbers 
MICROSOFT
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers % 1003.

Example :

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.

The root-to-leaf path 1->3 represents the number 13.

Return the sum = (12 + 13) % 1003 = 25 % 1003 = 25.
      
      
      
      void rootToLeafPath(TreeNode*root,string num,int &ans)
{
    if(!root) return;
    num+=to_string(root->val);
    num=to_string(stoi(num)%1003);
    if(!root->left && !root->right)
    { 
        ans=(ans%1003+stoi(num)%1003)%1003;
        return;
    }
    rootToLeafPath(root->left,num,ans);
    rootToLeafPath(root->right,num,ans);
}
int Solution::sumNumbers(TreeNode* A) { 
    if(!A) return 0;
    string num="";
    int ans=0; 
    rootToLeafPath(A,num,ans);
    return ans;
}
