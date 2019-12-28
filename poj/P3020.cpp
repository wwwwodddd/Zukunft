#include<iostream>
using namespace std;
int g[500][500];
int v[500],l[500];
int x[4]={0,0,1,-1};
int y[4]={1,-1,0,0};
char a[50][16];
int b[50][16];
int m,k,i,j,ans;
int t,n,h;
bool dfs(int x)
{
	for(int i=1;i<=h;i++)
		if(g[x][i]&&!v[i])
		{
			v[i]=1;
			if(l[i]==0||dfs(l[i]))
			{
				l[i]=x;
				return 1;
			}
		}
	return 0;
}
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>m>>k;
		memset(g,0,sizeof(g));
		memset(l,0,sizeof(l));
		memset(b,0,sizeof(b));
		for(i=1;i<=m;i++)
			for(j=1;j<=k;j++)
				cin>>a[i][j];
		h=n=0;
		for(i=1;i<=m;i++)
			for(j=1;j<=k;j++)
				if(a[i][j]=='*')
					if((i+j)&1)
						b[i][j]=++n;
					else
						b[i][j]=++h;
		int dx,dy;
		for(i=1;i<=m;i++)
			for(j=1;j<=k;j++)
				if(a[i][j]=='*'&&(i+j)&1)
				{
					for(int l=0;l<4;l++)
					{
						dx=x[l]+i;
						dy=y[l]+j;
						if(a[dx][dy]=='*')
						{
							g[b[i][j]][b[dx][dy]]=1;
						}
					}
				}
		ans=0;
		for(int i=1;i<=n;i++)
		{
			memset(v,0,sizeof(v));
			if(dfs(i))
				ans++; 
		}
		cout<<h+n-ans<<endl;
	}
	return 0;
}
