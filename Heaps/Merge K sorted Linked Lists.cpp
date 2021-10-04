Merge K Sorted Lists
Hard 
Merge k sorted linked lists and return it as one sorted list.

Example :

1 -> 10 -> 20
4 -> 11 -> 13
3 -> 8 -> 9
will result in

1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20
  
  
  
  struct compare {
    bool operator()(
        ListNode* a, ListNode* b)
    {
        return a->val > b->val;
    }
};
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    priority_queue<ListNode*,vector<ListNode*>,compare>pq;
    for(int i=0;i<A.size();i++)
    {
        if(A[i])
        pq.push(A[i]);
    }
    if(pq.empty()) return NULL;
    ListNode*dummy= new ListNode(0),*ans=dummy;
    while(!pq.empty())
    {
        ListNode* temp=pq.top();
        pq.pop();
        ans->next=temp;
        ans=ans->next;
        if(temp->next)
        pq.push(temp->next);
    }
    return dummy->next;
}
