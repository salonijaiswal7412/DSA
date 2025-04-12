int calcGCD(int n, int m){
    // Write your code here.
    if(m==0)
    return n;
    else 
    return calcGCD(m,n%m);
 
}
