Word Break II 
Given a string A and a dictionary of words B, add spaces in A to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

Note : Make sure the strings are sorted in your result.

Input Format:

The first argument is a string, A.
The second argument is an array of strings, B.
Output Format:

Return a vector of strings representing the answer as described in the problem statement.
Constraints:

1 <= len(A) <= 50
1 <= len(B) <= 25
1 <= len(B[i]) <= 20
Examples:

Input 1:
    A = "b"
    B = ["aabbb"]

Output 1:
    []

Input 1:
    A = "catsanddog",
    B = ["cat", "cats", "and", "sand", "dog"]

Output 1:
    ["cat sand dog", "cats and dog"] 
    
unordered_map<string,set<string>>mp;
set<string>wordBreakUtil(string A,vector<string>&B)
{
    set<string>res;
    if(mp.find(A)!=mp.end()) return mp[A];
    for(string word:B)
    {
        string sub=A.substr(0,word.size());
        if(sub==word)
        {
            if(A.size()==sub.size())
            {
                res.insert(sub);
            }
            else
            {
                set<string>temp = wordBreakUtil(A.substr(word.size()),B);
                for(auto curr:temp)
                res.insert(sub+" "+curr);
            }
        }
    }
    return mp[A]=res;
} 
vector<string> Solution::wordBreak(string A, vector<string> &B) 
{
    mp.clear();
    set<string>ans=wordBreakUtil(A,B); 
    vector<string>res;
    for(string curr:ans) 
    res.push_back(curr);
    return res;
    
}
