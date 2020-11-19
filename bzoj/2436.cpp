#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int n,m;
int l[420],r[420],t[420];
int s[420][420],f[420][420],g[420][420],z[420][420];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",l+i,r+i);
		r[i]+=l[i];
		t[m++]=l[i],t[m++]=r[i];
	}
	sort(t,t+m);
	m=unique(t,t+m)-t;
	for(int i=0;i<m;i++)
		for(int j=i+1;j<m;j++)
			for(int k=0;k<n;k++)
				if(t[i]<=l[k]&&r[k]<=t[j])
					s[i][j]++;
	memset(f,0xc0,sizeof f);
	memset(g,0xc0,sizeof g);
	for(int i=0;i<m;i++)
		for(int j=n;~j;j--)
			if(s[0][i]>=j)
			{
				f[i][j]=max(f[i][j+1],0);
				for(int k=0;k<i;k++)
				{
					f[i][j]=max(f[i][j],f[k][j]+s[k][i]);
					if(j>=s[k][i])
						f[i][j]=max(f[i][j],f[k][j-s[k][i]]);
				}
			}
	for(int i=m-1;~i;i--)
		for(int j=n;~j;j--)
			if(s[i][m-1]>=j)
			{
				g[i][j]=max(g[i][j+1],0);
				for(int k=i+1;k<m;k++)
				{
					g[i][j]=max(g[i][j],g[k][j]+s[i][k]);
					if(j>=s[i][k])
						g[i][j]=max(g[i][j],g[k][j-s[i][k]]);
				}
			}
	for(int i=0;i<m;i++)
		for(int j=i+1;j<m;j++)
			for(int x=0,y=n;x<=n;x++)
			{
				while(y>0&&min(s[i][j]+x+y,f[i][x]+g[j][y])<=min(s[i][j]+x+y-1,f[i][x]+g[j][y-1]))
					y--;
				z[i][j]=max(z[i][j],min(s[i][j]+x+y,f[i][x]+g[j][y]));
			}
	{
		int z=0;
		for(int i=0;i<=n;i++)
			z=max(z,min(i,f[m-1][i]));
		printf("%d\n",z);
	}
	for(int k=0;k<n;k++)
	{
		int u=0;
		for(int i=0;i<m;i++)
			if(t[i]<=l[k])
				for(int j=i+1;j<m;j++)
					if(t[j]>=r[k])
						u=max(u,z[i][j]);
		printf("%d\n",u);
	}
	return 0;
}
