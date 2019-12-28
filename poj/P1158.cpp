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
struct N
{
	int c,w,x,y;
	void scan()
	{
		char s[5];
		scanf("%s %d %d %d",s,&w,&x,&y);
		c=*s=='B';
		if(c)
			swap(x,y);
	}
}w[320];
int x,y,z,s,t,n,m;
int g[320][320];
int d[320];
int v[320];
int gc(int x,int y,int &z)
{
	if(y<w[x].w)
		return z=w[x].w-y,w[x].c;
	y-=w[x].w;
	y%=w[x].x+w[x].y;
	if(y<w[x].x)
		return z=w[x].x-y,1-w[x].c;
	else
		return z=w[x].x+w[x].y-y,w[x].c;
}
int wait(int x,int y,int z)
{
	int a,b,_=0;
	for(int i=0;i<3;i++)
	{
		if(gc(x,z,a)==gc(y,z,b))
			return _;
		_+=min(a,b);
		z+=min(a,b);
	}
	return 0x3f3f3f3f;
}
int main()
{
	scanf("%d %d",&s,&t);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		w[i].scan();
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		g[x][y]=g[y][x]=z;
	}
	memset(d,0x3f,sizeof d);
	d[s]=0;
	for(int j=1;j<=n;j++)
	{
		y=0x3f3f3f3f;
		for(int i=1;i<=n;i++)
			if(!v[i]&&d[i]<y)
				y=d[x=i];	
		if(x==t)
			break;
		v[x]=1;
		for(int i=1;i<=n;i++)
			if(!v[i]&&g[x][i])
			{
				z=wait(x,i,d[x]);
				if(d[i]>d[x]+g[x][i]+z)
					d[i]=d[x]+g[x][i]+z;
			}
	}
	if(d[t]==0x3f3f3f3f)
		puts("0");
	else
		printf("%d\n",d[t]);
}
