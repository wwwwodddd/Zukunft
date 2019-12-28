#include<iostream>
using namespace std;
int d[420];
int g[420][420];
int r[420][420];
int c[420];
int p[420];
int n,m;
int isap(int s,int t)
{
	c[0]=m;
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
int i,j,w,x,y,ans,M,N;
int z[420],zz,tp;
int main()
{
	scanf("%d %d %d",&M,&x,&y);
	memset(r,0,sizeof(r));
	for(i=1;i<=M;i++)
		r[i+M][i]=1;
	for(i=1;i<=M;i++)
		for(j=1;j<=M;j++)
		{
			scanf("%d",&w);
			if(w==1)
				r[i][j+M]=0xffffff;
		}
	m=2*M+1;
	memset(d,0,sizeof(d));
	memset(c,0,sizeof(c));
	memcpy(g,r,sizeof(r));
	ans=isap(x,y+M);
	if(r[x][y+M]||ans>=0xffffff)
	{
		printf("NO ANSWER!\n");
		return 0;
	}
	printf("%d\n",ans);
	for(i=1;i<=M&&ans;i++)
	{
		if(i==x||i==y)
			continue;
		if(g[i+M][i]||r[i+M][i]==0)
			continue;
		memset(d,0,sizeof(d));
		memset(c,0,sizeof(c));
		memcpy(g,r,sizeof(r));
		g[i+M][i]=0;
		tp=isap(x,y+M);
		if(tp!=ans)
		{
			z[zz++]=i;
			ans=tp;
			r[i+M][i]=0;
		}
	}
	for(i=0;i<zz;i++)
		printf("%d ",z[i]);
	printf("\n");
	return 0;
}