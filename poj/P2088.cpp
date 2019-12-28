#include<iostream>
using namespace std;
int n,v,g[20][20],f[(1<<20)],a[20];
void dfs(int x,int y,int z,int w)
{
	if(w<0)
		return;
	v=max(v,y);
	if(v==n)
		return;
	int i,j,k;
	for(i=0;i<n;i++)
		if((z&(1<<i))==0)
		{
			k=z|(1<<i);
			if(f[k]<w-g[x][i]-a[i])
			{
				f[k]=w-g[x][i]-a[i];
				dfs(i,y+1,k,f[k]);
			}
		}
}
int main()
{
	int i,j,k;
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&g[i][j]);
		v=0;
		memset(f,0xcc,sizeof(f));
		for(i=0;i<n;i++)
		{
			if(v==n)
				break;
			f[(1<<i)]=420-a[i];
			dfs(i,1,(1<<i),420-a[i]);
		}
		printf("%d\n",v);
	}
	return 0;
}