#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>
#include<map>
using namespace std;
int f[210][2];
int g[210][210];
int z[210];
int n;
void dfs(int u)
{
	int i;
	if(z[u])
	{
		for(i=1;i<=n;i++)
			if(g[u][i])
				dfs(i);
		for(i=1;i<=n;i++)
			if(g[u][i])
			{
				f[u][1]+=f[i][0];
				f[u][0]+=max(f[i][0],f[i][1]);
			}
			f[u][1]++;
	}
	else
	{
		f[u][0]=0;
		f[u][1]=1;
	}
}
int main()
{
	while(scanf("%d",&n)&&n)
	{
		int i,j,cnt=0;
		string str1,str2;
		int flag=1;
		map<string,int>m;
		memset(g,0,sizeof(g));
		memset(f,0,sizeof(f));
		memset(z,0,sizeof(z));
		cin>>str1;
		m[str1]=++cnt;
		for(i=1;i<n;i++)
		{
			cin>>str1>>str2;
			if(!m[str1])
				m[str1]=++cnt;
			if(!m[str2])
				m[str2]=++cnt;
			g[m[str2]][m[str1]]=1;
			z[m[str2]]=1;
		}
		dfs(1);
		printf("%d ",max(f[1][0],f[1][1]));
		if(n==2)
			goto end;
		for(i=1;i<=n;i++)
			if(f[i][1]==f[i][0])
				for(j=1;j<=n;j++)
					if(g[i][j]&&f[j][1]==f[j][0])
						goto end;
		printf("Yes\n");
		continue;
		end:
		printf("No\n");
	}
	return 0;
}
