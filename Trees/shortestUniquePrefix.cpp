Using Trie :-
  
Shortest Unique Prefix
  
Find shortest unique prefix to represent each word in the list.

Example:

Input: [zebra, dog, duck, dove]
Output: {z, dog, du, dov}
where we can see that
zebra = z
dog = dog
duck = du
dove = dov
NOTE : Assume that no word is prefix of another. In other words, the representation is always possible.
  
  
  
  #define maxlimit 256
struct TrieNode
{ 
    int freq;
    struct TrieNode* children[maxlimit]; //character rray
};

vector<string>ans;
TrieNode* newTrieNode()
{
    struct TrieNode* node = new TrieNode();
    node->freq=1;
    for(int i=0;i<maxlimit;i++)
    {
        node->children[i]= NULL;
    }
    return node;
}

void insert(TrieNode*root, string a)
{
    int len=a.size();
    struct TrieNode*temp=root;
   for(int i=0;i<len;i++)
   {
       int idx=a[i];
       if(!temp->children[idx])
       {
           temp->children[idx] = newTrieNode();
       }
       else
       {
           (temp->children[idx]->freq)++;
       }
       temp=temp->children[idx]; 
   }
}   
void findPrefixUtil(TrieNode*root,string s)
{
    if(!root) return;
    string res="";
    for(int i=0;i<s.size();i++)
    {
        int id=s[i];
        res+=s[i];
        if(root->children[id]->freq==1)
        {
            ans.push_back(res);
            return;
        }
        root=root->children[id];
    }
}
vector<string> Solution::prefix(vector<string> &A) {
    ans.clear();
    TrieNode* root=newTrieNode();
    root->freq=0;
    for(string st:A)
    {
        insert(root,st);
    }
    char prefix[maxlimit];
        for(string st:A)
        {
            findPrefixUtil(root,st);
        }
     return ans;
}
