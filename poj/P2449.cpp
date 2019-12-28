#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int d[10005];
struct N
{
	int v,d;
	N(){};
	N(int v,int d):v(v),d(d){};
};
struct E
{
	int v,w;
	E(){}
	E(int v,int w):v(v),w(w){};
	friend bool operator<(E a,E b)
	{
		return (a.w+d[a.v])>(b.w+d[b.v]);
	}
};
vector<N>g[10005];
vector<N>h[10005];
int n,m,s,t,k;
int v[10005];
void spfa(int s)
{
	int i;
	d[s]=0;
	v[s]=1;
	queue<int>q;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		v[u]=0;
		for(i=0;i<h[u].size();i++)
		{
			N p=h[u][i];
			if(d[p.v]>d[u]+p.d)
			{
				d[p.v]=d[u]+p.d;
				if(!v[p.v])
				{
					v[p.v]=true;
					q.push(p.v);
				}
			}
		}
	}
}
int a_star()
{
	if(s==t)
		k++;
	if(d[s]==0x3f3f3f3f)
		return -1;
	E z;
	priority_queue<E>q;
	q.push(E(s,0));
	while(!q.empty())
	{
		z=q.top();
		q.pop();
		v[z.v]++;
		if(v[t]==k)
			return z.w;
		if(v[z.v]<=k)
			for(int i=0;i<g[z.v].size();i++)
				q.push(E(g[z.v][i].v,z.w+g[z.v][i].d));
	}
	return -1;
}
int main()
{
	int i,a,b,l;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&l);
		g[a].push_back(N(b,l));
		h[b].push_back(N(a,l));
	}
	scanf("%d%d%d",&s,&t,&k);
	memset(d,0x3f,sizeof(d));
	spfa(t);
	memset(v,0,sizeof(v));
	printf("%d\n",a_star());
	return 0;
}