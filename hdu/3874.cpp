#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;
int a[50020];
int p[50020];
int h[50020];
int e[200020][2];
long long c[50020];
long long z[200020];
int n,m,x,t;
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
map<int,int>l;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		memset(h,0,sizeof h);
		memset(c,0,sizeof c);
		l.clear();
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",a+i),p[i]=l[a[i]],l[a[i]]=i;
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
			scanf("%d %d",e[i]+1,&x),e[i][0]=h[x],h[x]=i;
		for(int i=1;i<=n;i++)
		{
			if(p[i])
				R(p[i],-a[i]);
			R(i,a[i]);
			for(int j=h[i];j;j=e[j][0])
				z[j]=G(i)-G(e[j][1]-1);
		}
		for(int i=1;i<=m;i++)
			printf("%I64d\n",z[i]);
	}
	return 0;
}
