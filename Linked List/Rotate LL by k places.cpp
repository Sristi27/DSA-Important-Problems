Rotate List

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:

Given 1->2->3->4->5->NULL and k = 2,

return 4->5->1->2->3->NULL.
  
  
  
  /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int k) {
    if(!A || k==0) return A;
    int count=1; //5
    ListNode*head=A;
    while(head->next)
    {
        count+=1;
        head=head->next;
    }
    head->next=A;
    if(k>count) k=k%count;
    for(int i=0;i<count-k;i++)
    head=head->next;
    ListNode* newhead=head->next;
    head->next=NULL;
    return newhead;
}
