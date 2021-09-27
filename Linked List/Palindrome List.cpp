Palindrome List

Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.

Notes:

Expected solution is linear in time and constant in space.
For example,

List 1-->2-->1 is a palindrome.
List 1-->2-->3 is not a palindrome.

  
  
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
    ListNode*prev=NULL,*curr=head,*next;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
int Solution::lPalin(ListNode* A) {
    //go to the middle of ll 
    ListNode* head=A;
    ListNode*slow=head,*fast=head->next;
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    ListNode* sec =slow->next;
    ListNode* second = reverse(sec);
    slow->next=NULL;
    while(head && second)
    {
        if(head->val!=second->val) return 0;
        head=head->next;
        second=second->next;
    }
    return 1;
}
