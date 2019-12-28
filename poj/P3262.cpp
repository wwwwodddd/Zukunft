#include<stdio.h>
#include<stdlib.h>
int f[100020][2];
int n,i;
long long sum,ans;
int cmp(const void *a,const void *b)
{
	return ((int*)a)[0]*((int*)b)[1]-((int*)b)[0]*((int*)a)[1];
}
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&f[i][0],&f[i][1]);
		sum+=f[i][1];
	}
	qsort(f,n,8,cmp);
	for(i=0;i<n;i++)
	{
		sum-=f[i][1];
		ans+=sum*f[i][0];
	}
	printf("%I64d",ans*2);
	return 0;
}