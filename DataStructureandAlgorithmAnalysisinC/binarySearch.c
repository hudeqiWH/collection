#include <stdio.h>
#include <stdlib.h>
#define NotFound -1
typedef int ElementType;

int binarySearch(const ElementType a[],ElementType x, int n)
{
	int low,mid,high;

	low = 0;
	high = n-1;
	while(low <= high)
	{
		mid = (low + high)/2;
		if( a[mid] < x)
		{
			low = mid + 1;
		}
		else
		if (a[mid] > x)
		{
			high = mid-1;
		}
		else
			return mid;
	}
	return NotFound;
}

int main()
{
	int myarray[7] = {0,1,2,3,4,5,6};
	int index = 0;
	scanf("%d",&index);
	index = binarySearch(myarray,5,6);

	printf("The result is %d\n",index);

	return 0;
}

