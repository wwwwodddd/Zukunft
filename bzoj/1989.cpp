#include<stdio.h>
#include<string.h>
int a[20020][2],tot;
int h[10020];
int i,n,x,y;
double ans,t;
void add(int x,int y)
{
	tot++;
	a[tot][0]=h[x];
	a[tot][1]=y;
	h[x]=tot;
}
int dfs(int x,int y)
{
	int i,u=1;
	for(i=h[x];i;i=a[i][0])
		if(a[i][1]!=y)
			u+=dfs(a[i][1],x);
	t=(n-u)*u/(n*(n-1)/2.);
	ans+=t*t;
	return u;
}
int main()
{
	while(scanf("%d",&n)+1)
	{
		ans=0;
		tot=0;
		memset(h,0,sizeof(h));
		for(i=1;i<n;i++)
		{
			scanf("%d %d",&x,&y);
			add(x,y);
			add(y,x);
		}
		dfs(1,0);
		printf("%.6lf\n",ans);
	}
	return 0;
}