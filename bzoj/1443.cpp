#include<stdio.h>
#include<iostream>
using namespace std;
int a[200020][3],tot=1;
int h[10020];
int v[10020];
int z[10020];
char c[120][120];
int now,n,m,s,t,fg;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
void add(int x,int y,int z)
{
	tot++;
	a[tot][0]=h[x];
	a[tot][1]=y;
	a[tot][2]=z;
	h[x]=tot;

	tot++;
	a[tot][0]=h[y];
	a[tot][1]=x;
	a[tot][2]=0;
	h[y]=tot;
}
int dfs(int x,int y)
{
	if(x==t)
		return y;
	v[x]=fg;
	for(int i=h[x];i;i=a[i][0])
		if(a[i][2]&&v[a[i][1]]!=fg)
		{
			int k=dfs(a[i][1],min(y,a[i][2]));
			if(k)
				return a[i][2]-=k,a[i^1][2]+=k,k;
		}
	return 0;
}
int type(int x)
{
	return (x/m+x%m)%2;
}
void dfs(int x)
{
	v[x]=fg;
	if(type(x)==now)
		z[x]=1;
	for(int i=h[x];i;i=a[i][0])
		if(a[i][2]==now&&v[a[i][1]]!=fg)
			dfs(a[i][1]);
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%s",c[i]);
	s=n*m,t=s+1;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(c[i][j]!='#')
				if(i+j&1)
				{
					add(s,i*m+j,1);
					for(int k=0;k<4;k++)
					{
						int x=i+dx[k],y=j+dy[k];
						if(x>=0&&x<n&&y>=0&&y<m&&c[x][y]!='#')
							add(i*m+j,x*m+y,1);
					}
				}
				else
					add(i*m+j,t,1);
	fg++;
	while(int d=dfs(s,0xffff))
		fg++;
	fg++;
	now=1;
	dfs(s);
	fg++;
	now=0;
	dfs(t);
	int ed=0;
	for(int i=0;i<n*m;i++)
		if(z[i])
			ed=1;
	if(ed)
	{
		puts("WIN");
		for(int i=0;i<n*m;i++)
			if(z[i])
				printf("%d %d\n",i/m+1,i%m+1);
	}
	else
		puts("LOSE");
	return 0;
}
