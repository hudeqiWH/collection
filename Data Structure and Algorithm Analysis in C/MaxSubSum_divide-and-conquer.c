#include <stdio.h>
#include <stdlib.h>
int max3(int a,int b,int c)
{
    if((a<b))
    {
        if(b<c)
            return c;
        else
            return b;
    }
    else
    {
        if(a<c)
            return c;
        else
            return a;
    }
}
static int maxSubSum(const int a[],int left,int right)
{
	int maxLeftSum,maxRightSum;
	int maxLeftBorderSum,maxRightBorderSum;
	int leftBorderSum,rightBorderSum;
	int center,i;

	if(left == right) //Base case
	{
		if (a[left] > 0)
		{
			return a[left];
		}
		else
		{
			return 0;
		}
	}

	center = (left + right) / 2;
	maxLeftSum = maxSubSum(a,left,center);
	maxRightSum = maxSubSum(a,center+1,right);

	maxLeftBorderSum = 0;leftBorderSum = 0;
	for(i = center; i>= left;i--)
	{
		leftBorderSum += a[i];
		if(leftBorderSum > maxLeftBorderSum)
			maxLeftBorderSum = leftBorderSum;
	}

	maxRightBorderSum = 0;rightBorderSum = 0;
	for(i = center+1;i <= right;i++)
	{
		rightBorderSum += a[i];
		if(rightBorderSum > maxRightBorderSum)
			maxRightBorderSum = rightBorderSum;
	}

	return max3(maxLeftSum,maxRightSum,maxLeftBorderSum+maxRightBorderSum);
}

int maxSubsequenceSum(const a[],int N)
{
	return maxSubSum(a,0,N-1);
}

int main()
{
	int myarray[7] = {4,-3,5,2,-1,2,-2};
	int maxSubSeq = 0;

	maxSubSeq = maxSubsequenceSum(myarray,6);

	printf("The result is %d\n",maxSubSeq);
	return 0;
}
