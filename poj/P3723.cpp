#include<iostream>
#include<stdlib.h>
using namespace std;
int n,m,f[20010];
int i,t,s,ans;
int a[50010][3];
int cmp(const void *a,const void *b)
{
	return ((int*)b)[2]-((int*)a)[2];
}
int F(int x)
{
	return x==f[x]?x:f[x]=F(f[x]);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&n,&m,&s);
		for(i=0;i<s;i++)
		{
			scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
			a[i][1]+=n;
		}
		for(int i=0;i<=n+m;i++)
			f[i]=i;
		qsort(a,s,12,cmp);
		ans=10000*(n+m);
		for(i=0;i<s;i++)
		{
			int x=F(a[i][0]);
			int y=F(a[i][1]);
			if(x==y)
				continue;
			f[y]=x;
			ans-=a[i][2];
		}
		printf("%d\n",ans);
	}
	return 0;
}

