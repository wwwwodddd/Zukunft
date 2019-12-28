#include<iostream>
#define INF 0x3fffffff
using namespace std;
int d[105];
int r[105][105],sum,ssum;
double g[105][105];
int c[105];
int p[105];
int n,m;
double ll,rr;
int w[105],u[105];
int v[105];
int du[105];
double isap(int s,int t)
{
	int i=s,j;
	double re=0,z;
	c[0]=m;
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
int i,j,k,x,y,z,M,N,ans;
double work()
{
	int i,j;
	double mid,flow;
	while(rr-ll>0.1/M/M)
	{
		mid=(ll+rr)/2;
		memset(d,0,sizeof(d));
		memset(c,0,sizeof(c));
		memset(g,0,sizeof(g));
		for(i=1;i<=M;i++)
			for(j=1;j<=M;j++)
				g[i][j]=r[i][j];
		for(i=1;i<=M;i++)
		{
			g[0][i]=N;
			g[i][M+1]=N+2*mid-du[i];
		}
		flow=isap(0,m-1);
		flow=(N*M-flow)/2;
		if(flow>0)
			ll=mid;
		else
			rr=mid;
	}
	return ll;
}
void dfs(int x)
{
	v[x]=1;
	for(int i=1;i<=M;i++)
		if(g[x][i]>0&&v[i]==0)
		{
			ans++;
			dfs(i);
		}
	return;
}
int main()
{
	scanf("%d %d",&M,&N);
	m=M+2;
	for(i=1;i<=N;i++)
	{
		scanf("%d %d",&x,&y);
		r[x][y]++;
		r[y][x]++;
		du[x]++;
		du[y]++;
	}
	if(N==0)
	{
		printf("%d\n%d\n",1,1);
		return 0;
	}
	ll=1/M;
	rr=M;
	work();
	double mid=(ll+rr)/2-0.1/M/M;
	memset(d,0,sizeof(d));
	memset(c,0,sizeof(c));
	memset(g,0,sizeof(g));
	for(i=1;i<=M;i++)
		for(j=1;j<=M;j++)
			g[i][j]=r[i][j];
	for(i=1;i<=M;i++)
	{
		g[0][i]=N;
		g[i][M+1]=N+2*mid-du[i];
	}
	isap(0,m-1);
	dfs(0);
	printf("%d\n",ans);
	for(i=1;i<=M;i++)
		if(v[i])
			printf("%d\n",i);
	return 0;
}