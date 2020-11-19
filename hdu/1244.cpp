#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int n,m,s[1020],l[30],f[1020][30];
int i,j,st;
int main()
{
	while(scanf("%d",&n),n)
	{
		scanf("%d",&m);
		for(i=1;i<=m;i++)
			scanf("%d",&l[i]);
		for (i=1;i<=n;i++)
			scanf("%d",&s[i]),s[i]+=s[i-1];
		st=0;
		memset(f,0,sizeof(f));
		for(i=1;i<=m;i++)
			for(st+=l[i],j=st;j<=n;j++)
				f[j][i]=max(f[j-1][i],f[j-l[i]][i-1]+s[j]-s[j-l[i]]);
		printf("%d\n",f[n][m]);
	}
	return 0;
}