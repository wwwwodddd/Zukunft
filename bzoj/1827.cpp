#include<stdio.h>
#include<iostream>
using namespace std;
int s[100020],sm;
int a[200020][3],tot;
int h[100020];
int n,x,y,z;
long long ans;
void add(int x,int y,int z)
{
	tot++;
	a[tot][0]=h[x];
	a[tot][1]=y;
	a[tot][2]=z;
	h[x]=tot;
}
void dfs(int x,int y)
{
	for(int i=h[x];i;i=a[i][0])
		if(a[i][1]!=y)
		{
			dfs(a[i][1],x);
			ans+=(long long)s[a[i][1]]*a[i][2];
			s[x]+=s[a[i][1]];
		}
}
void dfs(int x,int y,long long z)
{
	ans=min(ans,z);
	for(int i=h[x];i;i=a[i][0])
		if(a[i][1]!=y)
			dfs(a[i][1],x,ans+(long long)a[i][2]*(s[1]-s[a[i][1]]*2));
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",s+i);
	for(int i=1;i<n;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	dfs(1,0);
	dfs(1,0,ans);
	printf("%lld\n",ans);
	return 0;
}
