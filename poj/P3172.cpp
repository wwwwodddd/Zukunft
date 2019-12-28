#include<iostream>
using namespace std;
int i,n;
long long w[1020],s[1020],ans,m;
void dfs(int x,long long y)
{
	if(y>m||y+s[x]<=ans)
		return;
	if(y>ans)
		ans=y;
	if(x==0)
		return;
	dfs(x-1,y+w[x]);
	dfs(x-1,y);
}
int main()
{
	while(scanf("%d%I64d",&n,&m)+1)
	{
		for(i=1;i<=n;i++)
			scanf("%I64d",&w[i]);
		ans=0;
		for(i=1;i<=n;i++)
			s[i]=s[i-1]+w[i]; 
		dfs(n,0);
		printf("%I64d\n",ans);
	}
	return 0;
}