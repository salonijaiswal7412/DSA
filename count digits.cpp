int countDigits(int n){
	// Write your code here.
	int c=0;
	int x=n;
	while(n!=0){
		     if((n%10)!=0){
                       if (x % (n % 10) == 0) {

                         c++;
                       }
                     }
                n/=10;
	}
	return c;
}
