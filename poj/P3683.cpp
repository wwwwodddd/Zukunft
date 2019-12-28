#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
vector<int>a[2020];
vector<int>b[2020];
queue<int>q;
int low[2020],dfn[2020],r[2020],s[2020],v[2020],op[2020],d[2020],z[2020],in[2020];
int t,n,m,cnt,ss,scc,x,y;
struct P{int x,y,z;}p[2020];
void tarjan(int x)
{
	low[x]=dfn[x]=++cnt;
	s[ss++]=x;
	v[x]=1;
	fe(i,a[x])
		if(!dfn[*i])
			tarjan(*i),low[x]=min(low[x],low[*i]);
		else if(v[*i])
			low[x]=min(low[x],dfn[*i]);
	if(dfn[x]==low[x])
	{
		int u;
		do
		{
			u=s[--ss];
			v[u]=0;
			r[u]=scc;
		}
		while(u!=x);
		scc++;
	}
}
int scan()
{
	int x,y;
	scanf("%d:%d",&x,&y);
	return x*60+y;
}
void print(int x,int y)
{
	printf("%02d:%02d %02d:%02d\n",x/60,x%60,y/60,y%60);
}
int J(int sx,int lx,int sy,int ly)
{
	if(sx+lx>sy&&sy+ly>sx)
		return 1;
	return 0;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		p[i].x=scan(),p[i].y=scan(),scanf("%d",&p[i].z),p[i].y-=p[i].z;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(i!=j)
			{
				if(J(p[i].x,p[i].z,p[j].x,p[j].z))
					a[i*2].push_back(j*2+1);
				if(J(p[i].x,p[i].z,p[j].y,p[j].z))
					a[i*2].push_back(j*2);
				if(J(p[i].y,p[i].z,p[j].x,p[j].z))
					a[i*2+1].push_back(j*2+1);
				if(J(p[i].y,p[i].z,p[j].y,p[j].z))
					a[i*2+1].push_back(j*2);
			}
	for(int i=0;i<2*n;i++)
		if(!dfn[i])
			tarjan(i);
	for(int i=0;i<n;i++)
		if(r[i*2]==r[i*2+1])
		{
			puts("NO");
			goto end;
		}
	puts("YES");
	for(int i=0;i<n;i++)
		op[r[i*2]]=r[i*2+1],op[r[i*2+1]]=r[i*2];
	for(int i=0;i<2*n;i++)
		fe(j,a[i])
			if(r[i]!=r[*j])
				in[r[i]]++,b[r[*j]].push_back(r[i]);
	for(int i=0;i<scc;i++)
		if(!in[i])
			q.push(i);
	while(q.size())
	{
		int u=q.front();
		q.pop();
		if(z[u]==0)
			z[u]=1,z[op[u]]=-1;
		fe(i,b[u])
			if(!--in[*i])
				q.push(*i);
	}
	for(int i=0;i<n;i++)
		if(z[r[i*2]]==1)
			print(p[i].x,p[i].x+p[i].z);
		else
			print(p[i].y,p[i].y+p[i].z);
	end:
	return 0;
}
