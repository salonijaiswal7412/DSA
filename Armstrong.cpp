bool checkArmstrong(int n){
	//Write your code here
	int x=n;
	int c=0;
	while(x!=0)
	{
		c++;
		x/=10;
	}
	 x=n;int s=0;
	while(x!=0)
	{
		s=s+pow((x%10),c);
		x/=10;
	}
	return (s==n);
} 
