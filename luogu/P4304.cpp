#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int di[8]={1,2,2,1,-1,-2,-2,-1};
int dj[8]={2,1,-1,-2,2,1,-1,-2};
int a[500020][3];
int h[60020];
int v[60020];
int n,m,s,t;
int tot;
void add(int x,int y,int z)
{
	tot++;
	a[tot][0]=h[x];
	a[tot][1]=y;
	a[tot][2]=z;
	h[x]=tot;

	tot++;
	a[tot][0]=h[y];
	a[tot][1]=x;
	a[tot][2]=0;
	h[y]=tot;
}
int bfs()
{
	int now,p,i;
	memset(v,0,sizeof v);
	v[s]=1;
	queue<int>q;
	q.push(s);
	while(q.size())
	{
		now=q.front();
		q.pop();
		for(i=h[now];i;i=a[i][0])
		{
			if(!v[a[i][1]]&&a[i][2])
			{
				v[a[i][1]]=v[now]+1;
				q.push(a[i][1]);
				if(a[i][1]==t)
					return 1;
			}
		}
	}
	return 0;
}
int dinic(int x,int y)
{
	int u=y,k,i;
	if(x==t)
		return y;
	for(i=h[x];i;i=a[i][0])
	{
		if(u&&a[i][2]&&v[a[i][1]]==v[x]+1)
		{
			k=dinic(a[i][1],min(a[i][2],u));
			if(!k)
				v[a[i][1]]=0;
			u-=k;
			a[i][2]-=k;
			a[i^1][2]+=k;
		}
	}
	return y-u;
}
char c[220][220];
int main()
{
	scanf("%d", &n);
	tot=1;
	s=n*n;
	t=s+1;
	for(int i=0;i<n;i++)
		scanf("%s",c[i]);
	int ans=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(c[i][j]=='0')
			{
				ans++;
				if(i+j&1)
				{
					add(s,i*n+j,1);
					for(int k=0;k<8;k++)
					{
						int ni=i+di[k];
						int nj=j+dj[k];
						if(0<=ni&&ni<n&&0<=nj&&nj<n)
							add(i*n+j,ni*n+nj,1);
					}
				}
				else
					add(i*n+j,t,1);
			}
	while(bfs())
		while(int dd=dinic(s,inf))
			ans-=dd;
	printf("%d\n", ans);
	return 0;
}