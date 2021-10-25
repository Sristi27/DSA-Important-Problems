Problem Description

Given a string A consisting only of lowercase characters, we need to check whether it is possible to make this string a palindrome after removing exactly one character from this.

If it is possible then return 1 else return 0.



Problem Constraints
3 <= |A| <= 105

 A[i] is always a lowercase character.



Input Format
First and only argument is an string A.



Output Format
Return 1 if it is possible to convert A to palindrome by removing exactly one character else return 0.



Example Input
Input 1:

 A = "abcba"
Input 2:

 A = "abecbea"


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 We can remove character ‘c’ to make string palindrome
Explanation 2:

 It is not possible to make this string palindrome just by removing one character 




int Solution::solve(string A) {
    if(A.size()<=2) return 1;
    int i=0,j=A.size()-1,count=0;
    while(i<j)
    {
        if(A[i]==A[j])
        {
            i++;
            j--;
        }
        else
        {
            if(i+1==j && A[i]!=A[j])
            {
                count++;
                if(count>1) return 0;
                else
                return 1;
            }
            else if( i!=j-1 && A[i]==A[j-1])
            {
                count++;
                if(count>1) return 0;
                i++;
                j-=2;
            }
            else if(i+1!=j && A[i+1]==A[j])
            {
                count++;
                if(count>1) return 0;
                i+=2;
                j--;
            }
            else
            {
                return 0;
            }
        }
    }
    return 1;
}


o(n) Time Complexity
