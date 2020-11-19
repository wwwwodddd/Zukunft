#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int q[1000020],b,f;
int a[2000020][3];
int h[1000020];
int n;
long long d1[1000020];
long long d2[1000020];
int p[1000020];
long long c[1000020],m;
int x,y,z;
int l,r;
int l1,l2;
int tot;
void add(int x,int y,int z)
{
	tot++;
	a[tot][0]=h[x];
	a[tot][1]=y;
	a[tot][2]=z;
	h[x]=tot;
}
void F(int r,long long *d)
{
	int u,i;
	b=f=0;
	q[f++]=r;
	memset(d,0x3f,sizeof(c));
	d[r]=0;
	while(b<f)
	{
		u=q[b++];
		for(i=h[u];i;i=a[i][0])
			if(d[a[i][1]]>d[u]+a[i][2])
			{
				d[a[i][1]]=d[u]+a[i][2];
				q[f++]=a[i][1];
			}
	}
}
void gm(int &x,long long *d)
{
	x=0;
	int i;
	for(i=1;i<=n;i++)
		if(d[i]>d[x]||x==0)
			y=d[x=i]; 
}
int solve()
{
	int re=0;
	int t=0;;
	b=f=1;
	x=y=1;
	//q max b f 
	//p min x y 
	int i;
	for(i=1;i<=n;i++)
	{
		while(c[q[f-1]]<=c[i]&&f>b)
			f--;
		q[f++]=i;
		while(c[p[y-1]]>=c[i]&&y>x)
			y--;
		p[y++]=i;
		while(c[q[b]]-c[p[x]]>m)
		{
			t++;
			if(q[b]<=t)
				b++;
			if(p[x]<=t)
				x++;
		}
		re=max(re,i-t);
	}
	if(re>2000)
		re=re*2/2;
	return re;
}
int main()
{
	int i;
	scanf("%d %lld",&n,&m);
	for(i=1;i<n;i++)
	{
		scanf("%d %d",&y,&z);
		add(i+1,y,z);
		add(y,i+1,z);
	}
	F(1,d1);
	gm(l1,d1);
	F(l1,d1);
	gm(l2,d1);
	F(l2,d2);
	for(i=1;i<=n;i++)
		c[i]=max(d1[i],d2[i]);
	printf("%d",solve());
	return 0;
}