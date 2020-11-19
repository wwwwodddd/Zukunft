#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int a[200020][4],tot=1;
int h[1020];
int v[1020];
int d[1020];
int r[1020];
int p[1020];
int ans,cnt,flow;
int s,t,x,y;
vector<int>b[1020];
int ok(int x,int y)
{
	int z=(int)sqrt(y*y-x*x+1e-3);
	if(z*z+x*x==y*y&&__gcd(z,x)==1)
		return 1;
	return 0;
}
void add(int x,int y,int z,int w)
{
	tot++;
	a[tot][0]=h[x];
	a[tot][1]=y;
	a[tot][2]=z;
	a[tot][3]=w;
	h[x]=tot;

	tot++;
	a[tot][0]=h[y];
	a[tot][1]=x;
	a[tot][2]=0;
	a[tot][3]=-w;
	h[y]=tot;
}
void mk(int x,int y)
{
	v[x]=y;
	fe(i,b[x])
		if(!v[*i])
			mk(*i,3^y);
}
int spfa()
{
	memset(d,0xc0,sizeof d);
	memset(v,0,sizeof v);
	queue<int>q;
	d[s]=0;
	q.push(s);
	while(q.size())
	{
		int u=q.front();
		q.pop();
		v[u]=0;
		for(int i=h[u];i;i=a[i][0])
			if(a[i][2])
				if(d[a[i][1]]<d[u]+a[i][3])
				{
					d[a[i][1]]=d[u]+a[i][3];
					p[a[i][1]]=u;
					r[a[i][1]]=i;
					if(!v[a[i][1]])
					{
						v[a[i][1]]=1;
						q.push(a[i][1]);
					}
				}
	
	}
	return d[t]!=0xc0c0c0c0;
}
int main()
{
	scanf("%d %d",&x,&y);
	for(int i=x;i<=y;i++)
		for(int j=i+1;j<=y;j++)
			if(ok(i,j))
			{
				b[i].push_back(j);
				b[j].push_back(i);
			}
	s=x-1,t=y+1;
	for(int i=x;i<=y;i++)
		if(!v[i])
			mk(i,1);
	for(int i=x;i<=y;i++)
		if(v[i]==1)
		{
			add(s,i,1,0);
			fe(j,b[i])
				add(i,*j,1,i+*j);
		}
		else
			add(i,t,1,0);
	while(spfa())
	{
		cnt++;
		ans+=d[t];
		for(int i=t;i!=s;i=p[i])
		{
			a[r[i]][2]-=1;
			a[r[i]^1][2]+=1;
		}
	}
	printf("%d %d\n",cnt,ans);
	return 0;
}
