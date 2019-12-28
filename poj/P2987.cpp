#include<iostream>
using namespace std;
int d[5020];
int c[5020];
int p[5020];
int a[200020][4];
int h[5020];
int v[5020];
int n,m;
int tot;
void add(int x,int y,int z)
{
	tot++;
	a[tot][0]=h[x];
	a[tot][1]=x;
	a[tot][2]=y;
	a[tot][3]=z;
	h[x]=tot;
}
long long isap(int s,int t)
{
	int i=s,j,z;
	long long re=0;
	memset(p,-1,sizeof(p));
	p[s]=s;
	while(d[s]<m)
	{
		for(j=h[i];j;j=a[j][0])
			if(a[j][3]>0&&d[i]==d[a[j][2]]+1)
				break;
		if(j)
		{
			p[a[j][2]]=j;
			i=a[j][2];
			if(i==t)
			{
				z=0x7fffffff;
				for(i=t;i!=s;i=a[p[i]][1])
					z=min(z,a[p[i]][3]);
				for(i=t;i!=s;i=a[p[i]][1])
					a[p[i]][3]-=z,a[p[i]^1][3]+=z;
				re+=z;
			}
		}
		else
		{
			c[d[i]]--;
			if(c[d[i]]==0)
				return re;
			d[i]=m;
			for(j=h[i];j;j=a[j][0])
				if(a[j][3]>0)
					d[i]=min(d[i],d[a[j][2]]+1);
			c[d[i]]++;
			if(i!=s)
				i=a[p[i]][1];
		}
	}
	return re;
}
void dfs(int x)
{
	if(x==m-1)
		return;
	v[x]=1;
	for(int i=h[x];i;i=a[i][0])
		if(a[i][3]>0&&!v[a[i][2]])
			dfs(a[i][2]);
}
int i,j,w,x,y,z,M,ans;
long long sum;
int main()
{
	scanf("%d %d",&m,&n);
	tot=1;
	M=m;
	m=m+2;
	for(i=1;i<=M;i++)
	{
		scanf("%d",&w);
		if(w>0)
		{
			sum+=w;
			add(0,i,w);
			add(i,0,0);
		}
		else
		{
			add(i,m-1,-w);
			add(m-1,i,0);
		}
	}
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		add(x,y,0x3fffffff);
		add(y,x,0);
	}
	c[0]=m;
	sum-=isap(0,m-1);
	dfs(0);
	for(i=1;i<=M;i++)
		if(v[i])
			ans++;
	printf("%d %I64d",ans,sum);
	return 0;
}