Reverse Link List II
Medium
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:

Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:

Given m, n satisfy the following condition:

1 ≤ m ≤ n ≤ length of list.

Note 2:

Usually the version often seen in the interviews is reversing the whole linked list which is obviously an easier version of this question.
  
  
  /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 ListNode*reverse(ListNode*A)
 {
     if(!A || !A->next) return A;
     ListNode*prev=NULL,*curr=A,*next;
     while(curr)
     {
         next=curr->next;
         curr->next=prev;
         prev=curr;
         curr=next;
     }
     return prev;
 }
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    ListNode*prev=NULL,*start=NULL,*end=NULL,*next=NULL,*curr=A;
    int i=1;
    while(curr)
    {
        if(i<B)
        {
            prev=curr;
        }
        if(i==B)
        {
            start=curr;
        }
        if(i==C)
        {
            next=curr->next;
            end=curr;
            break;
        }
        curr=curr->next;
        i+=1;
    }
    //sort this start->end
    end->next=NULL;
    end=reverse(start);
    if(prev)
    prev->next=end;
    else
    A=end;
    start->next=next;
    return A;
}
