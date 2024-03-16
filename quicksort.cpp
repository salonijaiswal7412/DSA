/*
	The function is called with the parameters:
	quickSort(input, 0, size - 1);

*/

int partitionArray(int input[], int start, int end) {
	// Write your code here
	int p=input[start];
	int i=start;
	int j=end;
	while(i<j)
	{
		while(input[i]<=p)i++;
		while(input[j]>p)j--;
		if(i<j)
		swap(input[i],input[j]);
	}
	swap(input[j],input[start]);
	return j;
}

void quickSort(int input[], int start, int end) {
        /*
                Don't write main().
                Don't read input, it is passed as function argument.
                Change in the given array itself.
                Taking input and printing output is handled automatically.
        */
        if (start < end) {
                int p = partitionArray(input, start, end);
                quickSort(input, start, p - 1);
                quickSort(input, p + 1, end);
        }
}
