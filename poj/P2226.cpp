#include<stdio.h>
#include<string.h>
#define I(x) for(i=1;i<=x;i++)
#define J(x) for(j=1;j<=x;j++)
char a[60][60];
int b[60][60],d[1000][1000],e[60][60];
int v[1000];
int l[1000];
int r,c,m,n,i,j,ans;
int dfs(int p)
{
	int i;
	I(d[p][0])
		if(!v[d[p][i]]&&d[p][i]!=0)
		{
		v[d[p][i]]=1;
		if(l[d[p][i]]==0||dfs(l[d[p][i]]))
			{
				l[d[p][i]]=p;
				return 1;
			}
		}
	return 0;
}
int main()
{
	scanf("%d %d",&r,&c);
	I(r)
		scanf("%s",a[i]+1);
	I(r)
		J(c)
			if(a[i][j]=='*')
			{
				m++;
				while(a[i][j]=='*'&&j<=c)
					b[i][j++]=m;
			}
	n=m;
	I(c)
		J(r)
			if(a[j][i]=='*')
			{
				m++;
				while(a[j][i]=='*'&&j<=r)
					e[j++][i]=m;
			}
	I(r)
		J(c)
			if(a[i][j]=='*')
			{
				d[b[i][j]][++d[b[i][j]][0]]=e[i][j];
				d[e[i][j]][++d[e[i][j]][0]]=b[i][j];
			}
	I(n)
	{
		memset(v,0,sizeof(v));
		if(dfs(i))
			ans++;
	}
	printf("%d\n",ans);
}