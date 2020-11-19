#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int n,m;
struct E
{
	int x,y,z;	
}e[200020];
int f[120];
int ans;
bool operator<(E a,E b)
{
	return a.z<b.z;
}
int F(int x)
{
	return f[x]!=x?f[x]=F(f[x]):x;
}
void U(int x,int y)
{
	f[F(x)]=F(y);
}
int main()
{
	while(scanf("%d %d",&n,&m),n)
	{
		ans=0;
		fr(i,n)
			scanf("%d %d %d",&e[i].x,&e[i].y,&e[i].z);
		sort(e,e+n);
		fo(i,n)
			f[i]=i;
		for(int i=0;i<n;i++)
			if(F(e[i].x)!=F(e[i].y))
				U(e[i].x,e[i].y),ans+=e[i].z,m--;
		if(m>1)
			puts("?");
		else
			printf("%d\n",ans);
	}
	return 0;
}
