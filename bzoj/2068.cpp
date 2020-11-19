#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int a[1000020],q[2000020],in[1000020],n;
bool c[1000020],tr[1000020];
int v[1000020],flg=1,g[1000020][2],sum[1000020],mn[1000020],f[1000020][2],ans=0;
void dfs(int x)
{
	int i;
	flg++;
	for(i=x;;i=a[i])
	{
		if(v[i]==flg)
			break;
		if(v[i])
			return;
		v[i]=flg;
	}
	for(;!c[i];i=a[i])
		c[i]=1;
}
void tdp()
{
	int i,bb,ff,s,v,tmp;
	bb=ff=0;
	for(i=1;i<=n;i++)
		if(!in[i])
			q[ff++]=i;
	memset(mn,0x3f,sizeof(mn));
	while(bb<ff)
	{
		s=q[bb++];
		v=a[s];
		tmp=max(g[s][0],g[s][1]);
		sum[v]+=tmp;
		mn[v]=min(mn[v],tmp-g[s][0]);
		in[v]--;
		if((!in[v])||c[v])
		{
			g[v][1]=sum[v]+1-mn[v];
			g[v][0]=sum[v];
			if(!c[v])
				q[ff++]=v;
			else
				tr[v]=1;
		}
	}
}
void cdp(int x)
{
	int i,ss=0,j,re=-1;
	for(i=x;c[i];i=a[i])
		q[++ss]=i,c[i]=0;
	for(j=0;j<2;j++)
	{
		f[1][j]=g[q[1]][j];
		f[1][!j]=0xc0000000;
		for(i=2;i<=ss;i++)
		{
			f[i][1]=f[i-1][0]+g[q[i]][1];
			f[i][1]=max(f[i][1],f[i-1][0]+g[q[i]][0]+1);
			if(tr[q[i]])
				f[i][1]=max(f[i][1],f[i-1][1]+g[q[i]][1]);
			f[i][0]=max(f[i-1][0],f[i-1][1])+g[q[i]][0];
		}
		if(!j)re=max(re,max(f[ss][0],f[ss][1]));
		else 
		{
			re=max(re,f[ss][0]);
			if(tr[q[1]])re=max(re,f[ss][1]);
		}
	}
	ans+=re;
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]),in[a[i]]++;
	for(i=1;i<=n;i++)
		if(!v[i])
			dfs(i);
	tdp();
	for(i=1;i<=n;i++)
		if(c[i])
			cdp(i);
	printf("%d\n",ans);
	return 0;
}