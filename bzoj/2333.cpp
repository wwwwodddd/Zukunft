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
int nx[300020],ed[300020];
int f[300020];
int s[300020],ss;
int a[300020];
int p[300020];
int n,m;
struct Q
{
	int o,x,y;
	void scan()
	{
		char s[3];
		scanf("%s",s);
		if(*s=='U')
			scanf("%d %d",&x,&y),o=1;
		else if(*s=='A'&&s[1]=='1')
			scanf("%d %d",&x,&y),o=2;
		else if(*s=='A'&&s[1]=='2')
			scanf("%d %d",&x,&y),o=3;
		else if(*s=='A'&&s[1]=='3')
			scanf("%d",&x),o=4;
		else if(*s=='F'&&s[1]=='1')
			scanf("%d",&x),o=5;
		else if(*s=='F'&&s[1]=='2')
			scanf("%d",&x),o=6;
		else if(*s=='F'&&s[1]=='3')
			o=7;
	}
}q[300020];
int mx[1200000],ad[1200000];
int F(int x)
{
	return f[x]!=x?f[x]=F(f[x]):x;
}
void bd(int x,int l,int r) 
{
	if(l==r)
	{
		mx[x]=s[l];
		return;
	}
	int m=l+r>>1;
	bd(x*2,l,m);
	bd(x*2+1,m+1,r);
	mx[x]=max(mx[x*2],mx[x*2+1]);
}
void add(int x,int d)
{
	mx[x]+=d,ad[x]+=d;
}
void pd(int x)
{
	if(ad[x])
	{
		add(x*2,ad[x]);
		add(x*2+1,ad[x]);
		ad[x]=0;
	}
}
void cg(int x,int L,int R,int l,int r,int d)
{
	if(l<=L&&R<=r)
		return add(x,d);
	if(R<l||L>r)
		return;
	pd(x);
	int M=L+R>>1;
	cg(x*2,L,M,l,r,d);
	cg(x*2+1,M+1,R,l,r,d);
	mx[x]=max(mx[x*2],mx[x*2+1]);
	return;
}
int qy(int x,int L,int R,int l,int r)
{
	if(l<=L&&R<=r)
		return mx[x];
	if(R<l||L>r)
		return 0xc0c0c0c0;
	pd(x);
	int M=L+R>>1;
	return max(qy(x*2,L,M,l,r),qy(x*2+1,M+1,R,l,r));
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	for(int i=1;i<=n;i++)
		f[i]=i,ed[i]=i,nx[i]=0;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		q[i].scan();
		if(q[i].o==1)
		{
			int X=F(q[i].x),Y=F(q[i].y);
			if(X==Y)
				continue;
			f[Y]=X;
			nx[ed[X]]=Y;
			ed[X]=ed[Y];
		}
	}
	for(int i=1;i<=n;i++)
		if(F(i)==i)
			for(int j=i;j;j=nx[j])
				p[j]=++ss,s[ss]=a[j];
	bd(1,1,n);
	for(int i=1;i<=n;i++)
		f[i]=i,ed[i]=i,nx[i]=0;
	for(int i=1;i<=m;i++)
		if(q[i].o==1)
		{
			int X=F(q[i].x),Y=F(q[i].y);
			if(X==Y)
				continue;
			f[Y]=X;
			nx[ed[X]]=Y;
			ed[X]=ed[Y];
		}
		else if(q[i].o==2)
			cg(1,1,n,p[q[i].x],p[q[i].x],q[i].y);
		else if(q[i].o==3)
			cg(1,1,n,p[F(q[i].x)],p[ed[F(q[i].x)]],q[i].y);
		else if(q[i].o==4)
			cg(1,1,n,1,n,q[i].x);
		else if(q[i].o==5)
			printf("%d\n",qy(1,1,n,p[q[i].x],p[q[i].x]));
		else if(q[i].o==6)
			printf("%d\n",qy(1,1,n,p[F(q[i].x)],p[ed[F(q[i].x)]]));
		else if(q[i].o==7)
			printf("%d\n",qy(1,1,n,1,n));
}
