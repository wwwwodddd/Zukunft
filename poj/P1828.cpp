#include<stdio.h>
#include<stdlib.h>
int a[50020][2];
int i,j,k;
int n,ans,max;
int cmp(const void *a,const void *b)
{
	if(*(int*)b==*(int*)a)
		return ((int*)b)[1]-((int*)a)[1];
	return *(int*)b-*(int*)a;
}
int main()
{
	while(scanf("%d",&n)&&n)
	{
		for(i=0;i<n;i++)
			scanf("%d %d",&a[i][0],&a[i][1]);
		qsort(a,n,8,cmp);
		max=a[0][1];
		ans=1;
		for(i=1;i<n;i++)
			if(a[i][1]>max)
			{
				ans++;
				max=a[i][1];
			}
		printf("%d\n",ans);
	}
	return 0;
}