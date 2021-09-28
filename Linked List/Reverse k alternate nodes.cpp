Reverse Alternate K Nodes 
Problem Description

Given a linked list A of length N and an integer B.

You need to reverse every alternate B nodes in the linked list A.



Problem Constraints
1 <= N <= 105
1<= Value in Each Link List Node <= 103
1 <= B <= N
N is divisible by B


Input Format
First argument is the head pointer of the linkedlist A.

Second argument is an integer B.



Output Format
Return the head pointer of the final linkedlist as described.



Example Input
Input 1:

 A = 3 -> 4 -> 7 -> 5 -> 6 -> 6 -> 15 -> 61 -> 16
 B = 3
 Input 2:

 A = 1 -> 4 -> 6 -> 6 -> 4 -> 10
 B = 2


Example Output
Output 1:

 7 -> 4 -> 3 -> 5 -> 6 -> 6 -> 16 -> 61 -> 15
Output 2:

 4 -> 1 -> 6 -> 6 -> 10 -> 4
   
  Solution :
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A, int k) 
{
    ListNode*dummy=new ListNode(NULL),*curr=dummy,*prev=dummy,*next=dummy,*head;
    dummy->next=A;
    head=dummy;
    int count=0;
    while(head)
    {
        count++;
        head=head->next;
    }
    while(prev->next && count>=k)
    {
        curr=prev->next,next=curr->next;
        for(int i=0;i<k-1;i++)
        {
            if(next)
            curr->next=next->next;
            else
            curr->next=NULL;
            if(next) 
            next->next=prev->next;
            prev->next=next;
            next=curr->next;
        }
        prev=curr;
        count-=k;
        int j=0;
        while(count>k && j<k && prev)
        {
            prev=prev->next;
            j++;
        }
        count-=k;
    }
    return dummy->next;
}
