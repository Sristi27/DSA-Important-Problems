Merge Two Sorted Lists



Merge two sorted linked lists and return it as a new list. 

The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

For example, given following linked lists :

  5 -> 8 -> 20 
  4 -> 11 -> 15
The merged list should be :

4 -> 5 -> 8 -> 11 -> 15 -> 20
  
  
  /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode*l1,*l2,*res;
    if(A->val<B->val)
    {
        res=A;
        l1=A;
        l2=B;
    }
    else
    {
        res=B;
        l1=B;
        l2=A;
    }
    while(l1!=NULL && l2!=NULL)
    {
        ListNode*temp=NULL;
        while(l1!=NULL && l1->val<=l2->val)
        {
            temp=l1;
            l1=l1->next;
        }
        temp->next=l2;
        //swap l1,l2
        ListNode*temp1=l1;
        l1=l2;
        l2=temp1;
    }
    return res;
    // a always has the smaller value 
}
