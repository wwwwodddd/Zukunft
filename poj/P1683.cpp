#include <iostream>
using namespace std ;
struct NODE
{
int a,b,c,d;
char x;
};
NODE p[100];
char s[10][10];
int f[10][10];
int csc,m,n,l;
bool check(int x,int y,int z)
{
	int i;
	for(i=0;i<l;i++)
	{
		if(x==p[i].a&&y==p[i].b&&f[p[i].c][p[i].d]!=0)
		{
			if(p[i].x=='R'&&f[p[i].c][p[i].d]!=z||p[i].x=='N'&&f[p[i].c][p[i].d]==z)
				return 0;
		}
	}
	return 1;
}
int dfs(int x,int z)
{
	int i;
	if(z==m+1)
		return 1;
	for(i=1;i<=m;i++)
	{
		if(f[x][i]!=0||!check(x,i,z))
			continue;
		f[x][i]=z;
		if(x==n)
		{
			if(dfs(1,z+1))
				return 1;
		}
		else
		{
			if(dfs(x+1,z))
				return 1;
		}
		f[x][i]=0;
	}
	return 0;
}
int main()
{
	int i,j,k;
	scanf("%d",&csc);
	while(csc--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
			scanf("%s",s[i]);
		l=0;
		while(1)
		{
			scanf("%d%d%s%d%d",&p[l].a,&p[l].b,&p[l].x,&p[l].c,&p[l].d);
			if(p[l].a==0)
				break ;
			l++;
			p[l].a=p[l-1].c;
			p[l].b=p[l-1].d;
			p[l].x=p[l-1].x;
			p[l].c=p[l-1].a;
			p[l].d=p[l-1].b;
			l++;
		}
		memset(f,0,sizeof(f));
		dfs(1,1);
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
				for(k=1;k<=m;k++)
					if(f[j][k]==i)
						cout<<s[j][k-1];
			puts("");
		}
		puts("");
	}
	return 0 ;
}