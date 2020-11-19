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
	while(scanf("%d %d",&n,&m),n+m)
	{
		memset(d,0x3f,sizeof d);
		while(m--)
		{
			scanf("%d %d %d",&x,&y,&z);
			d[x][y]=d[y][x]=min(d[x][y],z);
		}
		fo(k,n)
		fo(i,n)
		fo(j,n)
		d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		printf("%d\n",d[1][n]);
	}
	return 0;
}
