#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
int n,m,s,t,x,y,z;
int d[220][220];
int main()
{
	int i;
	while(scanf("%d %d",&n,&m)+1)
	{
		memset(d,0x3f,sizeof d);
		fr(k,n)
			d[k][k]=0;
		while(m--)
		{
			scanf("%d %d %d",&x,&y,&z);
			d[x][y]=d[y][x]=min(d[x][y],z);
		}
		fr(k,n)
			fr(i,n)
				fr(j,n)
					d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		scanf("%d %d",&s,&t);
		if(d[s][t]==0x3f3f3f3f)
			puts("-1");
		else
			printf("%d\n",d[s][t]);
	}
	return 0;
}
