#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct N
{
	int w,o,l,r;
	N(){}
	N(int w,int o,int l,int r):w(w),o(o),l(l),r(r){}
}a[200020];
int z[200020];
bool operator<(const N&a,const N&b)
{
	return a.w<b.w||a.w==b.w&&a.o<b.o;
}
int t,ac,n,m,l,r,x,k;
int c[200020];
int R(int x,int y)
{
	for(;x<=n;x+=x&-x)
		c[x]+=y;
}
int G(int x)
{
	int _=0;
	for(;x;x-=x&-x)
		_+=c[x];
	return _;
}
int main()
{
	for(scanf("%d",&t);t--;)
	{
		ac=0;
		memset(c,0,sizeof c);
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			a[ac++]=N(x,-1,i,0);
		}
		for(int i=0;i<m;i++)
		{
			scanf("%d %d %d",&l,&r,&x);
			a[ac++]=N(x,i,l,r);
		}
		sort(a,a+ac);
		for(int i=0;i<ac;i++)
		{
			if(~a[i].o)
				z[a[i].o]=G(a[i].r+1)-G(a[i].l);
			else
				R(a[i].l,1);
		}
		printf("Case %d:\n",++k);
		for(int i=0;i<m;i++)
			printf("%d\n",z[i]);
	}
	return 0;
}
