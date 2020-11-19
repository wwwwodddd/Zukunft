#include<stdio.h>
int h[400020];
int a[400020][2];
int tot,cnt;
int l[400020];
int r[400020];
int c[400020];
void add(int x,int y)
{
	tot++;
	a[tot][0]=h[x];
	a[tot][1]=y;
	h[x]=tot;
}
void dfs(int x,int y)
{
	int i;
	l[x]=++cnt;
	for(i=h[x];i;i=a[i][0])
		if(a[i][1]!=y)
			dfs(a[i][1],x);
	r[x]=++cnt;
}
void R(int x,int y)
{
	int i;
	for(i=x;i<=cnt;i+=i&-i)
		c[i]+=y;
}
int G(int x)
{
	int i,re=0;
	for(i=x;i;i-=i&-i)
		re+=c[i];
	return re;
}
int main()
{
	int i,x,y,n;
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		printf("%d\n",G(l[x]));
		R(l[x],1);
		R(r[x],-1);
	}
	return 0;
}