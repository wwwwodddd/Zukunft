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
int sm,ss,s,t,n,m,z;
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
int spfa()
{
	memset(d,0x3f,sizeof d);
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
				if(d[a[i][1]]>d[u]+a[i][3])
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
	return d[t]!=0x3f3f3f3f;
}
int main()
{
	scanf("%d %d",&n,&m);
	ss=2*n,s=ss+1,t=s+1;
	add(s,ss,m,0);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&z);	
		sm+=z;
		add(ss,i*2,m,0);
		add(i*2,i*2+1,z,-1000000);
		add(i*2+1,t,m,0);
	}
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		{
			scanf("%d",&z);	
			if(z!=-1)
				add(i*2+1,j*2,m,z);
		}
	while(spfa())
	{
		cnt++;
		ans+=d[t];
		for(int i=t;i!=s;i=p[i])
		{
			a[r[i]][2]--;
			a[r[i]^1][2]++;
		}
	}
	printf("%d\n",ans+sm*1000000);
	return 0;
}
