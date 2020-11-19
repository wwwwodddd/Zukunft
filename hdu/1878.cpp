#include<stdio.h>
#include<string.h>
int f[1020],n,m,x,y,d[1020];
int F(int x)
{
	return f[x]!=x?f[x]=F(f[x]):x;
}
void U(int x,int y)
{
	f[F(x)]=F(y);
}
int J()
{
	for(int i=1;i<=n;i++)
		if(F(1)!=F(i))
			return 0;
	for(int i=1;i<=n;i++)
		if(d[i]&1)
			return 0;
	return 1;
}
int main()
{
	while(scanf("%d %d",&n,&m),n)
	{
		memset(d,0,sizeof d);
		for(int i=1;i<=n;i++)
			f[i]=i;
		for(int i=0;i<m;i++)
			scanf("%d %d",&x,&y),d[x]++,d[y]++,U(x,y);
		printf("%d\n",J());
	}
}
