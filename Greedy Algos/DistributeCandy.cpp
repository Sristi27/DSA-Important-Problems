Distribute Candy 
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

1. Each child must have at least one candy.
2. Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

Input Format:

The first and the only argument contains N integers in an array A.
Output Format:

Return an integer, representing the minimum candies to be given.
Example:

Input 1:
    A = [1, 2]

Output 1:
    3

Explanation 1:
    The candidate with 1 rating gets 1 candy and candidate with rating cannot get 1 candy as 1 is its neighbor. 
    So rating 2 candidate gets 2 candies. In total, 2 + 1 = 3 candies need to be given out.

Input 2:
    A = [1, 5, 2, 1]

Output 2:
    7

Explanation 2:
    Candies given = [1, 3, 2, 1]
    
      
     
      
int Solution::candy(vector<int> &A) {
    int N = A.size();
    vector<int> left(N, 1); // all elements have 1(satisfy condt 1)
    for(int i = 1; i<N; i++){
        // if a rating is more than rating on its left, inc candy of said rating
        // by 1 more than no. of candy on left
        if(A[i] > A[i-1]) left[i] = left[i-1]+1;
    }
    vector<int> right(N,1);
    for(int i = N-2; i>=0; i--){
        // if a rating is more than rating on its right, inc candy of said rating
        // by 1 more than no. of candy on right
        if(A[i] > A[i+1]) right[i] = right[i+1]+1;
    }
    int total = 0;
    for(int i = 0; i<N; i++){
        // max of left2right and right2left candies will satisy condt 2(more candy than
        // both neighbours if higher rating)
        total += max(left[i], right[i]);
    }
    return total;
}
