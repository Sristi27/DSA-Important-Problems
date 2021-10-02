Find Permutation 
Given a positive integer n and a string s consisting only of letters D or I, you have to find any permutation of first n positive integer that satisfy the given input string.

D means the next number is smaller, while I means the next number is greater.

Notes

Length of given string s will always equal to n - 1
Your solution should run in linear time and space.
Example :

Input 1:

n = 3

s = ID

Return: [1, 3, 2]


Approach >. 2 pointer approach..numbers can be between [1....B]
So,traverse the string and see if current char is 'D' that means ele[i]>ele[i+1] and if curr char is 'I',that means ele[i]<ele[i+1]
Maintain two ptrs i=1 and j=B
traverse and insert numbers to the result vector


vector<int> Solution::findPerm(const string A, int B) {
    int i=1,j=B;
    vector<int>ans;
    for(char c:A)
    {
        if(c=='D')
        {
            ans.push_back(j);
            j--;
        }
        else
        {
            ans.push_back(i);
            i++;
        }
    }
    for(int k=i;k<=j;k++)
    ans.push_back(k);
    return ans;
}
