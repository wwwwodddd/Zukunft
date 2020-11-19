#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;
long long c[30020];
int h[30020];
int p[30020];
int w[30020];
int a[100020][2];
long long z[100020];
int t,n,q,x;
map<int,int>g;
void R(int x,int y)
{
	for(;x<=n;x+=x&-x)
		c[x]+=y;
}
long long G(int x)
{
	long long _=0;
	for(;x;x-=x&-x)
		_+=c[x];
	return _;
}
int main()
{
	for(scanf("%d",&t);t--;)
	{
		g.clear();
		memset(c,0,sizeof c);
		memset(p,0,sizeof p);
		memset(h,0,sizeof h);
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",w+i),p[i]=g[w[i]],g[w[i]]=i;
		scanf("%d",&q);
		for(int i=1;i<=q;i++)
			scanf("%d %d",a[i]+1,&x),a[i][0]=h[x],h[x]=i;
		for(int i=1;i<=n;i++)
		{
			if(p[i])
				R(p[i],-w[i]);
			R(i,w[i]);
			for(int j=h[i];j;j=a[j][0])
				z[j]=G(i)-G(a[j][1]-1);
		}
		for(int i=1;i<=q;i++)
			printf("%I64d\n",z[i]);
	}
}
