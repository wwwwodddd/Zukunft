#include<stdio.h>
int f[7]={0,6,4,5,2,3,1};
int d[10001][7];
int i,j,k,t,n,u,s,ms;
int F(int x,int u)
{
	int re=0;
	for(int i=1;i<=6;i++)
		if(i!=u&&i!=f[u]&&d[x][i]>re)
			re=d[x][i];
	return re;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ms=0;
		for(i=1;i<=n;i++)
			for(j=1;j<=6;j++)
				scanf("%d",&d[i][j]);
		for(i=1;i<=6;i++)
		{
			s=F(1,i);
			u=d[1][i];
			for(j=2;j<=n;j++)
				for(k=1;k<=6;k++)
					if(d[j][k]==u)
					{
						u=d[j][f[k]];
						s+=F(j,k);
						break;
					}
			s>ms?ms=s:0;
		}
		printf("%d\n",ms);
	}
	return 0;
}
