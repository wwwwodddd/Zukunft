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
int h[10020];
int v[10020];
int a[200020][3],tot;
int e[5000][3];
int n,m,l,s,t;
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
//	printf("%d %d %d\n",x,y,z);
}
int bfs()
{
	queue<int>q;
	memset(v,0,sizeof v);
	v[s]=1;
	q.push(s);
	while(q.size())
	{
		int x=q.front();
		q.pop();
		for(int i=h[x];i;i=a[i][0])
			if(a[i][2]&&!v[a[i][1]])
			{
				v[a[i][1]]=v[x]+1;
				if(a[i][1]==t)
					return 1;
				q.push(a[i][1]);
			}
	}
	return 0;
}
int dfs(int x,int y)
{
	if(x==t)
		return y;
	int u=0,k;
	for(int i=h[x];i;i=a[i][0])
		if(u<y&&a[i][2]&&v[a[i][1]]==v[x]+1)
		{
			k=dfs(a[i][1],min(a[i][2],y-u));
			u+=k;
			a[i][2]-=k;
			a[i^1][2]+=k;	
		}
	return u;
}
int ans,kk;
int main()
{
	s=9999,t=s+1;
	tot=1;
	scanf("%d %d %d",&n,&m,&l);
	for(int i=0;i<m;i++)
		scanf("%d %d %d",e[i],e[i]+1,e[i]+2);
	add(s,1,l);
	add(n,t,l);
	for(int i=1;i<=102;i++)
	{
		add(s,i*n+1,l);
		add(i*n+n,t,l);
		for(int j=0;j<m;j++)
			add(e[j][0]+(i-1)*n,e[j][1]+i*n,e[j][2]);
		while(bfs())
			while(kk=dfs(s,0x3f3f3f3f))
				ans+=kk;
		if(ans>=l)
		{
			printf("%d\n",i);
			break;	
		}
	}
	return 0;
}
