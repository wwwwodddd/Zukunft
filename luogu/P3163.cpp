#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int a[10020][3];
int h[120];
int v[120];
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
	a[tot][2]=z;
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
int sa,ta,na,sb,tb,nb;
char c[120][120];
bool work()
{
	long long ans;
	memset(h,0,sizeof h);
	tot=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<i;j++)
			if(c[i][j]=='N')
				add(i,j,inf);
			else if(c[i][j]=='O')
				add(i,j,1);
	add(s,sa,na);
	add(s,sb,nb);
	add(ta,t,na);
	add(tb,t,nb);
	ans=0;
	while(bfs())
		while(int dd=dinic(s,inf))
			ans+=dd;
	if(ans<na+nb)
		return false;
	memset(h,0,sizeof h);
	tot=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<i;j++)
			if(c[i][j]=='N')
				add(i,j,inf);
			else if(c[i][j]=='O')
				add(i,j,1);
	add(s,sa,na);
	add(s,tb,nb);
	add(ta,t,na);
	add(sb,t,nb);
	ans=0;
	while(bfs())
		while(int dd=dinic(s,inf))
			ans+=dd;
	if(ans<na+nb)
		return false;
	return true;
}
int main()
{
	while(scanf("%d%d%d%d%d%d%d",&n,&sa,&ta,&na,&sb,&tb,&nb)!=EOF)
	{
		s=n;
		t=n+1;
		for(int i=0;i<n;i++)
			scanf("%s",c[i]);
		printf("%s\n",work()?"Yes":"No");
	}
	return 0;
}