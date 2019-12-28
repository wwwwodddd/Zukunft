#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a[10020][2];
int d[10020];

int n,sum;
int cmp(const void *a,const void *b)
{
	return *(int *)b-*(int *)a;
}
int main()
{
	int i,j;
	while(scanf("%d",&n)!=EOF)
	{
		sum=0;
		memset(d,0,sizeof(d));
		for(i=0;i<n;i++)
			scanf("%d %d",&a[i][0],&a[i][1]);
		qsort(a,n,8,cmp);
		for(i=0;i<n;i++)
		{
			for(j=a[i][1];j>0;j--)
				if(d[j]==0)
				{
					d[j]=1;
					sum+=a[i][0];
					break;	
				}
		}
		printf("%d\n",sum);
	}
	return 0;	
}
