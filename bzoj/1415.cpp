#include<stdio.h>
#include<string.h>
#include<vector>
#include<iostream>
using namespace std;
vector<int>a[1020];
int n,m,s,t;
int p[1020][1020];
int d[1020][1020];
double f[1020][1020];
int v[1020];
int q[100020];
void bfs(int x)
{
	int b,f;
	d[x][x]=0;
	p[x][x]=x;
	memset(v,0,sizeof v);
	v[x]=1;
	b=f=0;
	q[f++]=x;
	for(;b<f;)
	{
		int u=q[b++];
		for(vector<int>::iterator i=a[u].begin();i!=a[u].end();i++)
			if(!v[*i])
			{
				v[*i]=1;
				d[x][*i]=d[x][u]+1;
				p[*i][x]=u;
				q[f++]=*i;
			}
			else if(d[x][*i]==d[x][u]+1&&u<p[*i][x])
				p[*i][x]=u;
	}
}
double work(int x,int y)
{
	if(f[x][y]>0)
		return f[x][y];
	if(x==y)
		return 0;
	int u=p[p[x][y]][y];
	if(u==y)
		return f[x][y]=1;
	f[x][y]=work(u,y);
	for(vector<int>::iterator i=a[y].begin();i!=a[y].end();i++)
		f[x][y]+=work(u,*i);
	return ++(f[x][y]/=a[y].size()+1);
}
int main()
{
	scanf("%d %d",&n,&m);
	scanf("%d %d",&s,&t);
	for(int i=0;i<m;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	memset(d,0x3f,sizeof d);
	for(int i=1;i<=n;i++)
		bfs(i);
	printf("%.3f",work(s,t));
	return 0;
}
