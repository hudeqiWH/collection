#include <stdio.h>
#include <stdlib.h>

int maxSubsequenceSum(const a[],int n)
{
	int thisSum,maxSum,j;
	thisSum = 0;
	maxSum = 0;

	for (j = 0; j < n; ++j)
	{
		thisSum += a[j];
		if(thisSum > maxSum)
		{
			maxSum = thisSum;
		}
		else if (thisSum < 0)
		{
			thisSum = 0;
		}
	}

	return maxSum;
}

int main()
{
	int myarray[7] = {4,-3,5,2,-1,2,-2};
	int maxSubSeq = 0;

	maxSubSeq = maxSubsequenceSum(myarray,6);

	printf("The result is %d\n",maxSubSeq);
	return 0;
}
