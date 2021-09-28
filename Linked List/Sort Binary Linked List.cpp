Sort Binary Linked List
Given a Linked List A consisting of N nodes.

The Linked List is binary i.e data values in the linked list nodes consist of only 0's and 1's.

You need to sort the linked list and return the new linked list.

NOTE:

Try to do it in constant space.


Problem Constraints
 1 <= N <= 105

 A.val = 0 or A.val = 1



Input Format
First and only argument is the head pointer of the linkedlist A.



Output Format
Return the head pointer of the new sorted linked list.



Example Input
Input 1:

 1 -> 0 -> 0 -> 1
Input 2:

 0 -> 0 -> 1 -> 1 -> 0


Example Output
Output 1:

 0 -> 0 -> 1 -> 1
Output 2:

 0 -> 0 -> 0 -> 1 -> 1
   
   
 Solution:

ListNode* Solution::solve(ListNode* A) {
    if(A==NULL) return A;
    ListNode*one=new ListNode(NULL),*oned,*zero=new ListNode(NULL),*zerod;
    oned=one;
    zerod=zero;
    while(A)
    {
        if(A->val==0)
        {
            zerod->next=A;
            A=A->next;
            zerod=zerod->next;
        }
        else
        {
            oned->next=A;  
            A=A->next;
            oned=oned->next;
        }
    }
    oned->next=NULL;
    zerod->next=one->next;
    return zero->next;
}
