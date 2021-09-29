2-Sum Binary Tree
Hard

Problem Description

Given a binary search tree A, where each node contains a positive integer, and an integer B, you have to find whether or not there exist two different nodes X and Y such that X.value + Y.value = B.

Return 1 to denote that two such nodes exist. Return 0, otherwise.



Problem Constraints
1 <= size of tree <= 100000

1 <= B <= 109



Input Format
First argument is the head of the tree A.

Second argument is the integer B.



Output Format
Return 1 if such a pair can be found, 0 otherwise.



Example Input
Input 1:

         10
         / \
        9   20


B = 19

Input 2:

 
          10
         / \
        9   20


B = 40



Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 10 + 9 = 19. Hence 1 is returned.
Explanation 2:

 No such pair exists.


   
   /**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::t2Sum(TreeNode* A, int B) {
    stack<TreeNode*>s1; //left inorder
    stack<TreeNode*>s2;  //reverse inorder
    TreeNode*curr1=A,*curr2=A;
    bool done1=false,done2=false;
    int val1=0,val2=0;
    while(1)
    {
        //left inorder
        while(done1==false)
        {
            if(curr1)
            {
                s1.push(curr1);
                curr1=curr1->left;
            }
            else
            {
                if(s1.empty()) done1=true;
                else
                {
                    curr1=s1.top();
                    s1.pop();
                    val1=curr1->val;
                    curr1=curr1->right;
                    done1=true;
                }
            }
        }

        while(done2==false)
        {
            if(curr2)
            {
                s2.push(curr2);
                curr2=curr2->right;
            }
            else
            {
                if(s2.empty()) done2=true;
                else
                {
                    curr2=s2.top();
                    s2.pop();
                    val2=curr2->val;
                    curr2=curr2->left;
                    done2=true;
                }
            }
        }
        if(val1!=val2 && val1+val2==B)
        return 1;

        else if(val1+val2 < B)
        {
            done1=false;
        }
        else if(val1+val2 > B)
        {
            done2=false;
        }
        if(val1>=val2) 
        return 0;
    }
    return 0;
}

//o(n) tc && o(logn) space comp
