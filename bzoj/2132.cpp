#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int n,m,s,t,sm,kk;
int h[16020];
int v[16020];
int a[2000020][3],tot;
int A[105][105];
int B[105][105];
int C[105][105];
void add(int x,int y,int z,int rz=0)
{
	sm+=z;
	tot++;
	a[tot][0]=h[x];
	a[tot][1]=y;
	a[tot][2]=z;
	h[x]=tot;

	tot++;
	a[tot][0]=h[y];
	a[tot][1]=x;
	a[tot][2]=rz;
	h[y]=tot;
}
int bfs()
{
	memset(v,0,sizeof v);
	v[s]=1;
	queue<int>q;
	q.push(s);
	while(q.size())
	{
		int u=q.front();
		q.pop();
		for(int i=h[u];i;i=a[i][0])
			if(a[i][2]&&!v[a[i][1]])
			{
				v[a[i][1]]=v[u]+1;
				q.push(a[i][1]);
				if(a[i][1]==t)
					return 1;
			}
	}
	return 0;
}
int dfs(int x,int y)
{
	if(x==t)
		return y;
	int u=0;
	for(int i=h[x];i;i=a[i][0])
		if(u<y&&a[i][2]&&v[a[i][1]]==v[x]+1)
		{
			int k=dfs(a[i][1],min(a[i][2],y-u));
			if(!k)
				v[a[i][1]]=0;
			a[i][2]-=k;
			a[i^1][2]+=k;
			u+=k;
		}
	return u;
}
int main()
{
	scanf("%d %d",&n,&m);
	s=n*m,t=s+1;
	tot=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",A[i]+j);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",B[i]+j);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",C[i]+j);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(i+j&1)
				swap(A[i][j],B[i][j]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			add(s,i*m+j,A[i][j]);
			add(i*m+j,t,B[i][j]);
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			if(j+1<m)
				add(i*m+j,i*m+j+1,C[i][j]+C[i][j+1],C[i][j]+C[i][j+1]);
			if(i+1<n)
				add(i*m+j,i*m+m+j,C[i][j]+C[i+1][j],C[i][j]+C[i+1][j]);
		}
	while(bfs())
		while(kk=dfs(s,0x3fffffff))
			sm-=kk;
	printf("%d",sm);
	return 0;
}
