#include<stdio.h>
#include<string.h>
int v[10020];
int u[10020];
int b[10020][35];
int c[10020];
int p[2000],pp,mx,n,q;
long long f[10020];
long long ans;
void div(int x)
{
	if(c[q])
		return;
	int i;
	for(i=1;i*i<x;i++)
		if(x%i==0)
			b[x][++c[x]]=i;
	if(x==i*i)
		b[x][++c[x]]=i;
	return;
}
void dfs(int x,int y,int z)
{
	if(y&1)
		u[x]=1;
	else
		u[x]=-1;
	for(int i=z;i<pp;i++)
	{
		if(x*p[i]>mx)
			return;
		dfs(x*p[i],y+1,i+1);
	}
}
int S(int x)
{
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			return 0;
	return 1;
}
int main()
{
	int i,j,k;
	for(i=2;i<2500;i++)
		if(S(i))
			p[pp++]=i;
	mx=2500;
	dfs(1,1,0);
	for(i=0;i<=10000;i++)
		f[i]=(long long)i*(i-1)*(i-2)*(i-3)/24;
	while(scanf("%d",&n)+1)
	{
		ans=mx=0;
		memset(v,0,sizeof(v));
		while(n--)
		{
			scanf("%d",&q);
			div(q);
			for(j=c[q];j>0;j--)
			{
				v[b[q][j]]++;
				if(b[q][j]*b[q][j]!=q)
					v[q/b[q][j]]++;
			}
			if(q>mx)
				mx=q;
		}
		for(i=0;i<=mx;i++)
			ans+=u[i]*f[v[i]];
		printf("%I64d\n",ans);
	}
	return 0;	
}