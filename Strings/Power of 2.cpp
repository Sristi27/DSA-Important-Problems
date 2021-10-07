int Solution::power(string A) {
    int N = A.length();
    int num = A[0]-'0';
    for(int i = 1; i<N; i++){ 
        num = (num*10)+(A[i]-'0'); 
    }
    if(num == 1) return 0; 
    int power = log(num)/log(2);
    
    if(pow(2,power) == num) return 1;
    else return 0; 
    return 0;
}
