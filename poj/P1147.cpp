#include<stdio.h>
int a[3020],b[3020];
int main()
{
	int i,j,k=0;
	int n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",a+i);
	for(i=0;i<n;i++)
		if(!a[i])
			b[k++]=i;
	for(i=0;i<n;i++)
		if(a[i])
			b[k++]=i;
	j=0;
	for(i=0;i<n;i++)
	{
		j=b[j];
		printf("%d ",a[j]);
	}
	return 0;
}