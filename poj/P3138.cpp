#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int a[120],v[120],s,t,m,x,y,z,k;
int main()
{
	while(scanf("%d %d %d",&s,&t,&m),s+t+m)
	{
		memset(v,0,sizeof v);
		memset(a,0,sizeof a);
		for(int i=0;i<s;i++)
			scanf("%d %d %d",&x,&y,&z),a[x]=y+z;
		for(int i=0;i<t;i++)
			scanf("%d %d",&x,&y),v[x]|=y>=m;
		z=0;
		for(int i=1;i<=s;i++)
			z+=min(a[i]+v[i],3);
		printf("Case %d: %d\n",++k,z);
	}
	return 0;
}
