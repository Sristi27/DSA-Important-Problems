Fraction
Medium

40

17

Add to favorites
Asked In:
AMAZON
MICROSOFT
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

Example :

Given numerator = 1, denominator = 2, return "0.5"
Given numerator = 2, denominator = 1, return "2"
Given numerator = 2, denominator = 3, return "0.(6)"
  
  
  
  
  
  string Solution::fractionToDecimal(int A, int B) {
    unordered_map<int,int>mp;
    string s="";
    long long int a=A,b=B;
    if(A==0) return "0";
    if((a<0 && b>0) || (a>0 && b<0)) 
    s="-";
    
    a=abs(a);
    b=abs(b);
    if(b==1) return s+to_string(a);
    // cout<<a<<" "<<b<<" "<<s<<endl;
    long long int x= a/b; //12
    long long int d=a%b; //1
    // cout<<x<<endl;
    s+=to_string(x);
    if(d==0) return s;
    else
    {
        string ans1=".";
        long long int m=d,i=1;
        while(mp.find(m)==mp.end() && m!=0)
        {
            ans1+=to_string((m*10)/b);
            mp[m]=i;
            i++;
            m=(m*10)%b;
        }
        if(m!=0)
        {
            ans1.insert(mp[m],"(");   
            ans1 += ")";
        }
        s+=ans1;
    }
     return s;
    
}
