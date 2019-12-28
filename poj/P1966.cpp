#include<iostream>
using namespace std;
int d[105];
int g[105][105];
int r[105][105];
int c[105];
int p[105];
int n,m;
int isap(int s,int t)
{
	int re=0,i=s,j,z;
	memset(p,-1,sizeof(p));
	p[s]=s;
	while(d[s]<m)
	{
		for(j=0;j<m;j++)
			if(g[i][j]>0&&d[i]==d[j]+1)
				break;
		if(j<m)
		{
			p[j]=i;
			i=j;
			if(i==t)
			{
				z=0x7fffffff;
				for(i=t;i!=s;i=p[i])
					z=min(z,g[p[i]][i]);
				for(i=t;i!=s;i=p[i])
					g[p[i]][i]-=z,g[i][p[i]]+=z;
				re+=z;
			}
		}
		else
		{
			c[d[i]]--;
			if(c[d[i]]==0)
				return re;
			d[i]=m;
			for(j=0;j<m;j++)
				if(g[i][j]>0)
					d[i]=min(d[i],d[j]+1);
			c[d[i]]++;
			i=p[i];
		}
	}
	return re;
}
int main()
{
	int i,j,x,y,z,ans;
	while(scanf("%d %d ",&m,&n)+1)
	{
		ans=m;
		memset(r,0,sizeof(r));
		for(i=0;i<m;i++)
			r[i+m][i]=1;
		for(i=0;i<n;i++)
		{
			scanf("(%d,%d) ",&x,&y);
			r[x][y+m]=0xffffff;
			r[y][x+m]=0xffffff;
		}
		for(i=0;i<m;i++)
			for(j=i+1;j<m;j++)
			{
				memset(d,0,sizeof(d));
				memset(c,0,sizeof(c));
				memcpy(g,r,sizeof(r));
				m*=2;
				c[0]=m;
				ans=min(ans,isap(i,j+m/2));
				m/=2;
			}
		printf("%d\n",ans);
	}
	return 0;
}