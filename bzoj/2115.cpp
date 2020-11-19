#include<stdio.h>
#include<string.h>
#include<vector>
#include<iostream>
using namespace std;
struct E
{
	int p,y;
	long long w;	
}a[200020];
int tot,n,m;
int h[50020];
long long d[50020];
long long ans;
long long v[100];
vector<long long>f;
void add(int x,int y,long long z)
{
	tot++;
	a[tot].p=h[x];
	a[tot].y=y;
	a[tot].w=z;
	h[x]=tot;
}
void dfs(int x)
{
	if(x==n)
		ans=d[x];
	for(int i=h[x];i;i=a[i].p)
		if(d[a[i].y]==-1)
		{
			d[a[i].y]=d[x]^a[i].w;
			dfs(a[i].y);
		}
		else if(d[x]^d[a[i].y]^a[i].w)
			f.push_back(d[x]^d[a[i].y]^a[i].w);
}
int main()
{
	scanf("%d%d",&n,&m);
	memset(d,-1,sizeof d);
	while(m--)
	{
		int x,y;
		long long z;
		scanf("%d%d%lld",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	d[1]=0;
	dfs(1);
	for(vector<long long>::iterator i=f.begin();i!=f.end();i++)
		for(int j=63;j>=0;j--)
			if(*i>>j&1)
				if(v[j])
					*i^=v[j];
				else
				{
					v[j]=*i;
					break;
				}
	for(int i=63;i>=0;i--)
		if((ans>>i&1)==0)
			ans^=v[i];
	printf("%lld",ans);
	return 0;
}
