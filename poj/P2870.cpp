#include<stdio.h>
#include<string.h>
#define fr(i,n) for(int i=0;i<n;i++)
int l[10][10],d[10][10],c[10][10],a[10][10],n,m,q,ans;
bool ok(int x,int y)
{
	if(a[x-1][y]>-1&&c[x-1][y]!=a[x-1][y])
		return 0;
	if(a[x][y-1]>-1&&c[x][y-1]>a[x][y-1])
		return 0;
	if(a[x+1][y]>-1&&c[x+1][y]>a[x+1][y])
		return 0;
	if(a[x][y+1]>-1&&c[x][y+1]>a[x][y+1])
		return 0;
	return 1;
}
void dfs(int x,int y,int w,int z)
{
	if(z>=ans)
		return;
	if(y>m)
	{
		if(x==n)
		{
			for(int i=1;i<=m;++i)
				if(d[x][i]>0||a[x][i]>-1&&c[x][i]!=a[x][i])
					return;
			ans=z;
			return;
		}
		for(int i=1;i<=m;++i)
			l[x+1][i]=l[x][i];
		dfs(x+1,1,0,z);
		return;
	}
	if(a[x][y]<-1)
	{
		if(!l[x][y]&&!w)
		{
			for(int i=y-1;i>0;i--)
				if(a[x][i]<-1)
					d[x][i]--;
				else
					break;
			l[x][y]=1;
			d[x][y]=0;
			c[x-1][y]++,c[x+1][y]++,c[x][y-1]++,c[x][y+1]++;
			if(ok(x,y))
				dfs(x,y+1,1,z+1);
			for(int i=y-1;i>0;--i)
				if(a[x][i]<-1)
					d[x][i]++;
			else
				break;
			l[x][y]=0;
			c[x-1][y]--,c[x+1][y]--,c[x][y-1]--,c[x][y+1]--;
		}
		if(ok(x,y))
		{
			if(l[x][y])
				d[x][y]=0;
			else if(w)
				d[x][y]=d[x-1][y];
			else
				d[x][y]=d[x-1][y]+1;
			dfs(x,y+1,w,z);
		}
	}
	else if(d[x-1][y]>0)
		return;
	else if(ok(x,y))
		l[x][y]=0,dfs(x,y+1,0,z);
}
int main()
{
	int x,y,z;
	while(scanf("%d%d",&n,&m),n+m)
	{
		memset(d,0,sizeof(d));
		memset(l,0,sizeof(l));
		memset(c,0,sizeof(c));
		fr(i,n+2)
			fr(j,m+2)
				a[i][j]=-2;
		scanf("%d",&q);
		while(q--)
			scanf("%d%d%d",&x,&y,&z),a[x][y]=z;
		ans=0xffffff;
		dfs(1,1,0,0);
		if(ans<0xffffff)
			printf("%d\n",ans);
		else
			puts("No solution");
	}
	return 0;
}
