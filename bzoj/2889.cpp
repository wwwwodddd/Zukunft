#include<stdio.h>
int n,x,y,z;
int s[1000020];
int c[1000020];
int h[1000020],tot;
int a[2000020][2];
void dfs(int x,int y)
{
	s[x]=1;
	for(int i=h[x];i;i=a[i][0])
		if(a[i][1]!=y)
		{
			dfs(a[i][1],x);
			s[x]+=s[a[i][1]];
		}
}
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
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
		c[s[i]]++;
	for(int i=1;i<=n;i++)
		if(n%i==0)
		{
			int w=0;
			for(int j=i;j<=n;j+=i)
				w+=c[j];
			z+=w==n/i;
		}
	printf("%d",z);
	return 0;
}
