#include<iostream>
#define INF 0x3fffffff
using namespace std;
int d[420];
int g[420][420],sum,ssum;
long long r[420][420];
int c[420];
int p[420];
int n,m;
long long ll,rr;
int w[420],u[420];
int v[420][420];
int isap(int s,int t)
{
	int i=s,j,re=0,z;
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
int i,j,k,x,y,z,M,N;
long long work()
{
	int i,j;
	long long mid;
	while(ll<rr)
	{
		mid=(ll+rr)/2;
		memset(d,0,sizeof(d));
		memset(c,0,sizeof(c));
		memset(g,0,sizeof(g));
		for(i=1;i<=M;i++)
			g[0][i]=w[i];
		for(i=1;i<=M;i++)
			g[M+i][m-1]=u[i];
		for(i=1;i<=M;i++)
			for(j=1;j<=M;j++)
				if(r[i][j]<=mid)
					g[i][M+j]=INF;
		c[0]=m;
		if(isap(0,m-1)==sum)
			rr=mid;
		else
			ll=mid+1;
	}
	return ll;
}
int main()
{
	scanf("%d %d",&M,&N);
	m=2*M+2;
	for(i=1;i<=M;i++)
	{
		scanf("%d %d",&w[i],&u[i]);
		sum+=w[i];
		ssum+=u[i];
	}
	memset(r,0x3f,sizeof(r));
	for(i=0;i<N;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		r[x][y]=min(r[x][y],(long long)z);
		r[y][x]=min(r[y][x],(long long)z);
	}
	for(i=1;i<=M;i++)
		r[i][i]=0;
	for(k=1;k<=M;k++)
		for(i=1;i<=M;i++)
			for(j=1;j<=M;j++)
				r[i][j]=min(r[i][j],r[i][k]+r[k][j]);
	for(i=1;i<=M;i++)
		for(j=1;j<=M;j++)
			rr=max(rr,r[i][j]);
	long long pt=work();
	if(sum>ssum||work()==0x3f3f3f3f3f3f3f3fLL)
		printf("-1");
	else
		printf("%I64d",pt);
	return 0;
}