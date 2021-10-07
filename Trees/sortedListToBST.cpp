int count(ListNode*a)
 {
     int c=0;
     while(a)
     {
         a=a->next;
         c++;
     }
     return c;
 }
 TreeNode* util(ListNode*&A,int n)
 {
     if(!A || n<=0) return NULL;
     TreeNode*left=util(A,n/2);
     TreeNode* root= new TreeNode(A->val);
     root->left=left;
     A=A->next;
     if(A!=NULL)
     root->right = util(A,n-n/2-1);
     else
     root->right=NULL;
     return root;
 }
TreeNode* Solution::sortedListToBST(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n=count(A);
    // cout<<n<<endl;
    if(n==1)
    {
        TreeNode*root=new TreeNode(A->val);
        return root;
    }
    return util(A,n);
}
