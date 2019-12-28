#include<stdio.h>
int a[12][2]={3,2};
int main()
{
	for(int i=1;i<11;i++)
	{
		a[i][0]=a[i-1][0]*3+a[i-1][1]*4;
		a[i][1]=a[i-1][0]*2+a[i-1][1]*3;
		printf("%10d%10d\n",a[i][1]/2,(a[i][0]-1)/2);
	}
	return 0;
}
