#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int a[600020][2],tot;
int h[300020];
int q[300020],bb,ff;
int f[300020];
int v[300020];
int d[300020];
int s[300020],ss;
int da[300020];
int db[300020];
int in[300020];
int n,x,y;
void add(int x,int y)
{
	tot++;
	a[tot][0]=h[x];
	a[tot][1]=y;
	h[x]=tot;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		add(x,y);
		add(y,x);
		in[x]++;
		in[y]++;
	}
	q[ff++]=1;
	while(bb<ff)
	{
		int u=q[bb++];
		for(int i=h[u];i;i=a[i][0])
			if(!v[a[i][1]])
			{
				v[a[i][1]]=1;
				d[a[i][1]]=d[u]+1;
				q[ff++]=a[i][1];
			}
	}
	memset(v,0,sizeof v);
	bb=ff=x=y=0;
	for(int i=1;i<=n;i++)
		if(d[i]>y)
			y=d[x=i];
	v[q[ff++]=x]=1;
	while(bb<ff)
	{
		int u=q[bb++];
		for(int i=h[u];i;i=a[i][0])
			if(!v[a[i][1]])
			{
				f[a[i][1]]=u;
				v[a[i][1]]=1;
				d[a[i][1]]=d[u]+1;
				q[ff++]=a[i][1];
			}
	}
	bb=ff=x=y=0;
	for(int i=1;i<=n;i++)
		if(d[i]>y)
			y=d[x=i];
	memset(v,0,sizeof v);
	memset(d,0,sizeof d);
	for(;x;x=f[x])
		v[s[++ss]=x]=1;
	for(int i=1;i<=n;i++)
		if(in[i]==1&&!v[i])
			q[ff++]=i;
	while(bb<ff)
	{
		int u=q[bb++];
		d[f[u]]=d[u]+1;
		in[f[u]]--;
		if(in[f[u]]==1)
			q[ff++]=f[u];
	}
	for(int i=1;i<=ss;i++)
		da[i]=max(da[i-1],d[s[i]]+i-1);
	for(int i=ss;i>=1;i--)
		db[i]=max(db[i+1],d[s[i]]+ss-i);
	y=0x3f3f3f3f;
	for(int i=1;i<ss;i++)
	{
		int t=max(max(da[i],db[i+1]),(da[i]+1>>1)+(db[i+1]+1>>1)+1);
		if(t<y)
			y=t,x=i;
	}
	printf("%d\n",y);
	printf("%d %d\n",s[x+1],s[x]);
	printf("%d %d\n",s[ss-(db[x+1]+1>>1)],s[(da[x]+1>>1)+1]);
	return 0;
}
