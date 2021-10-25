Generate all Parentheses 
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem



int Solution::isValid(string A) {
    stack<char>s;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]=='(' || A[i]=='{' || A[i]=='[')
        {
            s.push(A[i]);
        }
        else
        {
            if(s.empty()) return 0;
            char ch=s.top();
            if(A[i]==')' && ch!='(') return 0;
            else if(A[i]==']' && ch!='[') return 0;
            else if(A[i]=='}' && ch!='{') return 0;
            s.pop();
        }
    }
    return s.size()==0;
}


TC , SC = o(n)
