#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int d[1020][1020][2];
int h[1000020];
int p[2000020],tot;
int dx[12],dy[12];
int l[2][1000020],lc[2];
char s[1020][1020];
int n,m,t;
bool ok(int x,int y)
{
	return x>=0&&y>=0&&x<n&&y<m&&s[x][y]!='*';	
}
void xlk(int x,int y,int z)
{
	if(d[x][y][z&1]!=-1)
		return;
	tot++;
	d[x][y][z&1]=z;
	int u=x*m+y;
	if(z&1)
		u+=n*m;
	p[u]=h[z];
	h[z]=u;
}
int main()
{
	memset(d,-1,sizeof d);
	memset(h,-1,sizeof h);
	scanf("%d %d %d",&n,&m,&t);
	fr(i,n)
	{
		scanf("%s",s[i]);
		fr(j,m)
			if(s[i][j]=='H')
				xlk(i,j,0),s[i][j]='.';
	}
	fr(i,t)
	{
		scanf("%d %d",dx+i,dy+i);
		dx[i+t]=-dx[i];
		dy[i+t]=-dy[i];
	}
	t<<=1;
	for(int k=0;tot;k++)
	{
		for(int j=h[k];~j;j=p[j])
		{
			int x=j/m%n,y=j%m,tx,ty;
			fr(i,t)
			{
				for(tx=x+dx[i],ty=y+dy[i];ok(tx,ty);tx+=dx[i],ty+=dy[i])
				{
					xlk(tx,ty,k+1);
					if(d[tx][ty][k&1]!=-1&&d[tx][ty][k&1]<=k||s[tx][ty]=='#')
						break;
				}	
				if(s[x][y]=='#')
				{
					tx=x+dx[i];
					ty=y+dy[i];
					if(ok(tx,ty)&&ok(x-dx[i],y-dy[i]))
						xlk(tx,ty,k+2);
				}
			}
			tot--;
		}
	}
	fr(i,n)
		fr(j,m)
			fr(k,2)
				if(d[i][j][k]!=-1)
					l[k][lc[k]++]=d[i][j][k];
	fr(i,2)
		sort(l[i],l[i]+lc[i]);
	int q,x,y;
	for(scanf("%d",&q);q--;)
	{
		scanf("%d",&x);
		y=x&1;
		printf("%d\n",upper_bound(l[y],l[y]+lc[y],x)-l[y]);
	}
	return 0;
}
