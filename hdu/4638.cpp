#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[100020];
int c[100020];
int l[100020];
int r[100020];
int p[100020];
int v[100020];
int z[100020];
int t,n,m;
int G(int x)
{
	int re=0;
	for(;x;x-=x&-x)
		re+=c[x];
	return re;
}
void R(int x,int y)
{
	for(;x<=n;x+=x&-x)
		c[x]+=y;
}
int cmp(const int&x,const int&y)
{
	return r[x]<r[y];
}
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		for(int i=0;i<m;i++)
			scanf("%d%d",l+i,r+i),p[i]=i;
		memset(v,0,sizeof v);
		memset(c,0,sizeof c);
		sort(p,p+m,cmp);
		for(int i=0,j=1;i<m;i++)
		{
			for(;j<=n&&j<=r[p[i]];j++)
			{
				if(v[a[j]-1])
					R(v[a[j]-1],-1);
				if(v[a[j]+1])
					R(v[a[j]+1],-1);
				R(j,1);
				v[a[j]]=j;
			}
			z[p[i]]=G(r[p[i]])-G(l[p[i]]-1);
		}
		for(int i=0;i<m;i++)
			printf("%d\n",z[i]);
	}
	return 0;
}
