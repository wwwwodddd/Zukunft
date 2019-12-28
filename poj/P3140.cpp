#include<stdio.h>
#include<string.h>
int e[200020][2];
int h[200020];
int d[200020];
int tot,i,k;
int x,y;
long long s,ans;
long long abs(long long x)
{
	return x>-x?x:-x;
}
void add(int x,int y)
{
	tot++;
	e[tot][0]=h[x];
	h[x]=tot;
	e[tot][1]=y;
	return;
}
long long dfs(int x,int y)
{
	long long re=0;
	for(int i=h[x];i;i=e[i][0])//少了int ，会死的很惨。
		if(e[i][1]!=y)
			re+=dfs(e[i][1],x);
	re+=d[x];
	if(abs(s-2*re)<ans)
		ans=abs(s-2*re);
	return re;
}
int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m)&&n+m)
	{
		s=tot=0;
		memset(h,0,sizeof(h));
		for(i=1;i<=n;i++)
		{
			scanf("%d",&d[i]);
			s+=d[i];
		}
		ans=s;
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&x,&y);
			add(x,y);
			add(y,x);
		}
		dfs(1,0);
		printf("Case %d: %I64d\n",++k,ans);
	}
	return 0;	
}