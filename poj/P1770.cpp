#include<iostream>
#include<algorithm>
using namespace std;
int f[201][2];
int n,a[201];
bool t[1000001], g[201][201];
void F(int x,int y)
{
	int i;
	f[x][0]=f[x][1]=0;
	for(i=1;i<=n;i++)
		if(i!=y&&g[i][x]==1)
		{
			F(i,x);
			f[x][0]+=f[i][1];
			f[x][1]+=f[i][0];
		}
	f[x][1]+=a[x];
	if(f[x][1]<f[x][0])
		f[x][1]=f[x][0];
}
int main()
{
	int m,p,i,j;
	while(scanf("%d %d",&n,&m)&&n+m)
	{
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		memset(t,0,sizeof(t));
		for(j=0;j<m;j++)
		{
			scanf("%d", &p);
			t[p]=1;
		}
		memset(g,0,sizeof(g));
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
				if(t[a[j]-a[i]])
					g[i][j]=g[j][i]=1;
		F(1,0);
		printf("%d\n",f[1][1]);
	}
	return 0;
}
