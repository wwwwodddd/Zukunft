#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int w[120][120];
int vx[120],vy[120],cnt;
int lx[120],ly[120];
int l[120];
int n,m,x,y,z,dd;
long long ans;
int dfs(int x)
{
	vx[x]=cnt;
	for(int y=1;y<=n;y++)
		if(vy[y]!=cnt)
			if(lx[x]+ly[y]==w[x][y])
			{
				vy[y]=cnt;
				if(!l[y]||dfs(l[y]))
					return l[y]=x,1;
			}
			else
				dd=max(dd,lx[x]+ly[y]-w[x][y]);
	return 0;
}
void KM()
{
	memset(lx,0,sizeof lx);
	memset(ly,0,sizeof ly);
	memset(l,0,sizeof l);
	for(int i=1;i<=n;i++)
	{
		for(;;)
		{
			cnt++;
			dd=0xc0000000;
			if(dfs(i))
				break;	
			for(int j=1;j<=n;j++)
			{
				if(vx[j]==cnt)
					lx[j]-=dd;
				if(vy[j]==cnt)
					ly[j]+=dd;
			}
		}
	}
}
int main()
{
	while(scanf("%d %d",&n,&m)+1)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				w[i][j]=10000;
		for(int i=0;i<m;i++)
		{
			scanf("%d %d %d",&x,&y,&z);
			w[x][y]=min(w[x][y],z);
		}
		KM();
		ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=w[l[i]][i];
			if(w[l[i]][i]>1000)
			{
				ans=-1;
				break;
			}
		}
		cout<<ans<<endl;
	}
}
