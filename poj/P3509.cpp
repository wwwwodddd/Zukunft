#include<iostream>
using namespace std;
int g[1002][1002],d[1002][1002],x[4002],y[4002];
int S(int p,int n)
{
	int r=p,c;
	int cnt=0;
	for(c=r;c<=(n-p);c++)
	{
		x[cnt]=g[r][c];
		y[cnt++]=d[r][c];
	}
	for(;r<=(n-p);r++)
	{
		x[cnt]=g[r][c];
		y[cnt++]=d[r][c];
	}
	for(;c>p;c--)
	{
		x[cnt]=g[r][c];
		y[cnt++]=d[r][c];
	}
	for(;r>p;r--){
		x[cnt]=g[r][c];
		y[cnt++]=d[r][c];
	}
	for(p=0;p<cnt;p++)
		if(x[p]==y[0])
			break;
	if(p==cnt)
		return 0;
	for(int i=(p+1)%cnt,j=1;j<cnt;i=(i+1)%cnt,j++)
		if(x[i]!=y[j])
			return 0;
	return 1;
}
int main()
{
	int n,l,i,j,k;
	int f,t=1;
	while(scanf("%d", &n)&&n)
	{
		for(i=1,k=1;i<=n;i++)
			for(j=1;j<=n;j++)
			{
				scanf("%d",&g[i][j]);
				d[i][j]=k++;
			}
		l=(n+1)/2;
		f=0;
		for(i=1;i<=l;i++)
		{
			if(i==l&&(n&1))
			{
				if(g[i][i]!=d[i][i])
					f=1;
				break;
			}
			if(!S(i, n))
			{
				f=1;
				break;
			}
		}
		printf("%d. %s\n",t++,f?"NO":"YES");
	}
	return 0;
}