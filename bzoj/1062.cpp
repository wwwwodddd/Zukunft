#include<stdio.h>
#include<iostream>
using namespace std;
int len,p,n,m;
int a[2020][3030];
int b[2020][3030];
int t[200020];
int l[200020];
int c[1000020];
void R(int a[2020][3030],int x,int y,int z)
{
	for(x++;x<=n;x+=x&-x)
		for(int j=y;j<=m;j+=j&-j)
			a[x][j]+=z;
}
int G(int a[2020][3030],int x,int y)
{
	if(x<0||y<0)
		return 0;
	int _=0;
	for(x=min(x+1,n);x;x-=x&-x)
		for(int j=y;j;j-=j&-j)
			_+=a[x][j];
	return _;
}
int S(int a[2020][3030],int xa,int ya,int xb,int yb)
{
	return G(a,xb,yb)+G(a,--xa,--ya)-G(a,xa,yb)-G(a,xb,ya);
}
int Q(int t,int l,int r)
{
	int o=r==len;
	return S(a,t-r,l+n-t,t,m)+S(b,t+1,t+1+l,t+r,m)+S(a,t-r+o+n,l-t,n,m)+S(b,0,l+t-n+1,t+r-o-n,m);
}
void cg(int i,int d)
{
	R(a,t[i],l[i]+n-t[i],d);
	R(b,t[i],l[i]+t[i]+1,d);
}
int main()
{
	int q,u,w,x,y,z,k;
	scanf("%d %d",&q,&len);
	n=len*2;
	m=len*3;
	while(q--)
	{
		scanf("%d %d",&k,&u);
		if(k==1)
		{
			scanf("%d %d %d %d",&w,&x,&y,&z);
			c[w]=++p;
			l[p]=y-x;
			t[p]=(u+n-z*x)%n;
			cg(c[w],1);
		}
		else if(k==2)
		{
			scanf("%d %d",&x,&y);
			printf("%d\n",Q(u%n,x,y));
		}
		else
			scanf("%d",&w),cg(c[w],-1);
	}
}
