#include<iostream>
using namespace std;
int n,m,a[10],la,ans,z,v[10],av[10];
char c[10];
void dfs(int x,int s,int d)
{
	if(s+d>m)
		return;
	if(x==la)
	{
		s+=d;
		if(ans==s)
		{
			z=1;
			return;
		}
		if(s<=m&&s>ans)
		{
			z=0;
			ans=s;
			memcpy(av,v,sizeof(v));
		}
		return;
	}
	dfs(x+1,s,d*10+a[x]);
	v[x]=1;
	dfs(x+1,s+d,a[x]);
	v[x]=0;
}
void print()
{
	int i;
	if(ans==-1)
	{
		printf("error\n");
		return;
	}
	if(z)
	{
		printf("rejected\n");
		return;
	}
	printf("%d ",ans);
	for(i=0;i<la;i++)
	{
		if(av[i])
			putchar(' ');
		printf("%d",a[i]);
	}
	printf("\n");
}
int main()
{
	int i;
	while(scanf("%d%s",&m,c),m+c[0]-'0')
	{
		la=strlen(c);
		for(i=0;i<la;i++)
			a[i]=c[i]-'0';
		memset(v,0,sizeof(v));
		ans=-1;
		z=0;
		dfs(1,0,a[0]);
		print();
	}
	return 0;
}