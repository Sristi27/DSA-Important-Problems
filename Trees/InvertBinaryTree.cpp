
TreeNode* Solution::invertTree(TreeNode* A) 
{
    if(!A) return A;
    TreeNode*left=invertTree(A->left);
    TreeNode*right=invertTree(A->right);
    A->left=right;
    A->right=left;
    return A;
}
