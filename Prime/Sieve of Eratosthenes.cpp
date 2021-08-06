//Sieve of Eratosthenes
// this algo basically find prime no s in a range
// or all primes which are smaller than n -> most efficient algo



#include <bits/stdc++.h>

using namespace std;

//n=12
// 1->t 2->t  3->t 4->f 5->t 6->f 7->t 8->f 9->f 10->f 11->t 12 ->f
void sievePrime(int n) 
{
    bool primes[n+1];
    memset(primes,true,sizeof(primes));
    for(int i=2;i*i<=n;i++)
    {
        if(primes[i]==true)
        {
            for(int j=i*i;j<=n;j+=i)
            {
                primes[j]=false;
            }
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(primes[i]==true) cout<<i<<endl;
    }
    
}
int main()
{
    cout<<"Find all prime numbers less than the given value:"<<endl;
    int n;
    cin>>n;
    sievePrime(n);
}


//time complexity -> o(n*log(logn)) -> euler + taylor + harmonic mean of all primes
// https://www.geeksforgeeks.org/segmented-sieve/
