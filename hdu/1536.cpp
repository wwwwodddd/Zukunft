#include<stdio.h>
#include<string.h>
#define fr(i,n) for(int i=0;i<n;i++)
int sg[10020];
int v[1020];
int a[120];
int t,n,m;
int SG(int x)
{
	if(sg[x]+1)
		return sg[x];
	fr(i,m)
		if(x>=a[i])
			SG(x-a[i]);
	fr(i,m)
		if(x>=a[i])
			v[sg[x-a[i]]]=x;
	int i;
	for(i=0;v[i]==x;i++)
		;
	return sg[x]=i;
}
int main()
{
	while(scanf("%d",&m),m)
	{
		fr(i,m)
			scanf("%d",a+i);
		memset(sg,-1,sizeof sg);
		sg[0]=0;
		scanf("%d",&t);
		fr(i,t)
		{
			int x,z=0;
			scanf("%d",&n);
			fr(j,n)
				scanf("%d",&x),z^=SG(x);
			printf("%s",z?"W":"L");
		}
		puts("");
	}
	return 0;
}
