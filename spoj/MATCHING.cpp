#include<bits/stdc++.h>
#define BUFSIZE 20000000
char buf[BUFSIZE],*pt=buf;
#define scan(t)\
{\
	t=0;\
	while(*pt<'0'||*pt>'9')\
		pt++;\
	while(((*pt)>='0'&&(*pt)<='9'))\
	t=t*10+*pt++-'0';\
}
using namespace std;
int e[1000020][3];
int h[100020];
int v[100020];
int tot,i,x,y,z,n,m,k,s,t,flag;
int ans;
void add(int x,int y,int z)
{
	tot++;
	e[tot][0]=h[x];
	e[tot][1]=y;
	e[tot][2]=z;
	h[x]=tot;

	tot++;
	e[tot][0]=h[y];
	e[tot][1]=x;
	e[tot][2]=0;
	h[y]=tot;
}
int bfs()
{
	int now,p,i;
	memset(v,0,sizeof(v));
	v[s]=1;
	queue<int>q;
	q.push(s);
	while(q.size())
	{
		now=q.front();
		q.pop();
		for(i=h[now];i;i=e[i][0])
		{
			if(!v[e[i][1]]&&e[i][2])
			{
				v[e[i][1]]=v[now]+1;
				q.push(e[i][1]);
				if(e[i][1]==t)
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
	for(i=h[x];i;i=e[i][0])
	{
		if(u&&e[i][2]&&v[e[i][1]]==v[x]+1)
		{
			k=dinic(e[i][1],min(e[i][2],u));
			if(!k)
				v[e[i][1]]=0;
			u-=k;
			e[i][2]-=k;
			e[i^1][2]+=k;
		}
	}
	return y-u;
}
int main()
{
	fread(buf,1,BUFSIZE,stdin);
	scan(n);
	scan(m);
	scan(k);
	tot=1;
	for(i=0;i<k;i++)
	{
		scan(x);
		scan(y);
		add(x,y+n,1);
	}
	s=0,t=n+m+1;
	for(int i=1;i<=n;i++)
		add(s,i,1);
	for(int i=n+1;i<=n+m;i++)
		add(i,t,1);
	while(bfs())
		while(int dd=dinic(s,0xffffff))
			ans+=dd;
	printf("%d",ans);
	return 0;
}