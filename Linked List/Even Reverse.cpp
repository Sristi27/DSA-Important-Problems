Even Reverse 

Problem Description

Given a linked list A , reverse the order of all nodes at even positions.



Problem Constraints
1 <= Size of linked list <= 100000



Input Format
First and only argument is the head of the Linked-List A.



Output Format
Return the head of the new linked list.



Example Input
Input 1:

A = 1 -> 2 -> 3 -> 4
Input 2:

A = 1 -> 2 -> 3


Example Output
Output 1:

 1 -> 4 -> 3 -> 2
Output 2:

 1 -> 2 -> 3


Example Explanation
Explanation 1:

Nodes are positions 2 and 4 have been swapped.
Explanation 2:

No swapping neccassary here.
  
  
  
  /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverse(ListNode*head)
{
    ListNode*prev=new ListNode(NULL),*curr=head,*next;
    while(curr)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
ListNode* Solution::solve(ListNode* A) {
    //make a separate list of nodes at even position
    //reverse that and add to original list 
    // o(n) & o(n)
    vector<int>res;
    ListNode*curr=A,*dummy=new ListNode(NULL),*temp=dummy;
    int count=1;
    while(curr)
    {
        if(count%2==0)
        res.push_back(curr->val);
        curr=curr->next;
        count++;
    }
    count=1;
    int j=res.size()-1;
    curr=A;
    while(curr)
    {
        if(count%2==0)
        {
            curr->val = res[j];
            j--;
        }
        count++;
        curr=curr->next;
    }
    return A;
}



PArt 2:


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverse(ListNode*head)
{
    ListNode*prev=new ListNode(NULL),*curr=head,*next;
    while(curr)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
ListNode* Solution::solve(ListNode* A) {
    //make a separate list of nodes at even position
    //reverse that and add to original list 
    // o(n) & o(n)
    vector<int>res;
    ListNode*curr=A,*dummy=new ListNode(NULL),*temp=dummy;
    int count=1;
    while(curr)
    {
        if(count%2==0)
        res.push_back(curr->val);
        curr=curr->next;
        count++;
    }
    count=1;
    int j=res.size()-1;
    curr=A;
    while(curr)
    {
        if(count%2==0)
        {
            curr->val = res[j];
            j--;
        }
        count++;
        curr=curr->next;
    }
    return A;
}



