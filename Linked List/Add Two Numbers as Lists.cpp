Add Two Numbers as Lists
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)

Output: 7 -> 0 -> 8

    342 + 465 = 807
Make sure there are no trailing zeros in the output list

So, 7 -> 0 -> 8 -> 0 is not a valid response even though the value is still 807.
  
  
  /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    int sum=0,carry=0;
    ListNode*dummy=new ListNode(NULL);
    ListNode*res=dummy;
    while(A || B || carry)
    {
        sum=0;
        if(A!=NULL)
        {
            sum+=A->val;
            A=A->next;
        }
        if(B!=NULL)
        {
            sum+=B->val;
            B=B->next;
        }
        if(carry) 
        sum+=carry;

        carry=sum/10;
        sum=sum%10;
        
        res->next=new ListNode(sum);
        res=res->next;
    }
    return dummy->next;
}


o(max(m,n))
  m and n->length of linked lists a,b
