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
int n,s,t,ans,kk;
int h[64020];
int v[64020];
int a[2000020][3],tot;
char b[42][42][42];
int dx[]={1,0,0,-1,0,0};
int dy[]={0,1,0,0,-1,0};
int dz[]={0,0,1,0,0,-1};
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
int times;
int dfs(int x,int y)
{
	times++;
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
int in(int x,int y,int z)
{
	return x>=0&&x<n&&y>=0&&y<n&&z>=0&&z<n;
}
int cg(int x,int y,int z)
{
	return (x*n+y)*n+z;
}
int main()
{
	scanf("%d",&n);
	s=n*n*n,t=s+1;
	tot=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%s",b[i][j]);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
				if(i+j+k&1)
					if(b[i][j][k]=='P')
						b[i][j][k]='N';
					else if(b[i][j][k]=='N')
						b[i][j][k]='P';
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
			{
				for(int l=0;l<6;l++)
				{
					int I=i+dx[l],J=j+dy[l],K=k+dz[l];
					if(in(I,J,K))
						add(cg(i,j,k),cg(I,J,K),1);
				}
				if(b[i][j][k]=='P')
					add(s,cg(i,j,k),0xffffff);
				if(b[i][j][k]=='N')
					add(cg(i,j,k),t,0xffffff);
			}
	ans=3*n*n*(n-1);
	while(bfs())
		while(kk=dfs(s,0xffffff))
			ans-=kk;
	printf("%d\n",ans);
	return 0;
}
