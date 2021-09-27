Swap List Nodes in pairs

Add to favorites
Asked In:
MICROSOFT
AMAZON

Given a linked list, swap every two adjacent nodes and return its head.

For example,

Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

Solution (CPP)

  /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* head) {
    ListNode* dummy=new ListNode(NULL),*temp=dummy,*curr=dummy,*next=dummy,*prev=dummy;
    dummy->next=head;
    while(prev->next)
    {
        curr=prev->next;
        next=curr->next;
        if(next)
        {
            curr->next=next->next;
            prev->next=next;
            next->next=curr;
            prev=curr;
        }
        else
        {
            curr->next=NULL;
            break;
        }
    }
    return dummy->next;
}
