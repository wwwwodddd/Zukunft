#include<stdio.h>
#include<stdlib.h>
int n,i,k,a[50001];
long long t;
int cmp(const void *a,const void *b)
{
	return abs(*(int*)a)-abs(*(int*)b);
}
int main()
{
	while(scanf("%I64d%d",&t,&n)+1)
	{
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		qsort(a,n,4,cmp);
		t-=abs(a[0]);
		for(k=0;k<n;k++)
		{
			if(t<0)
				break;
			t-=abs(a[k]-a[k+1]);
		}
		printf("%d\n",k);
	}
	return 0;
}
