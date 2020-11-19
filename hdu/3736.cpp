#include<stdio.h>
#include<string.h>
int v[21][21][21][21];
int f[21][21][21][21];
int g[21][805];
int t,n,m,x,y,mo=123456789;
long long F(int w,int x,int y,int z)
{
	if(!w)
		return !y&&!z;
	int &t=f[w][x][y][z];
	if(v[w][x][y][z])
		return t;
	v[w][x][y][z]=1;
	t=(t+F(w-1,x,y,z));
	if(y)
		t=(t+F(w-1,x+1,y-1,z)*(x+1))%mo;
	if(z)
		t=(t+F(w-1,x,y+1,z-1)*(y+1))%mo;
	if(y>1)
		t=(t+F(w-1,x+2,y-2,z)*(x+2)*(x+1)/2)%mo;
	if(z>1)
		t=(t+F(w-1,x,y+2,z-2)*(y+2)*(y+1)/2)%mo;
	if(z)
		t=(t+F(w-1,x+1,y,z-1)*(x+1)*y)%mo;
	return t;
}
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d %d",&n,&m);
		memset(g,0,sizeof g);
		g[0][0]=1;
		for(int l=1;l<=n;l++)
		{
			scanf("%d %d",&x,&y);
			for(int i=0;i<=m;i++)
				if(g[l-1][i])
					for(int j=0;j<=y&&i+j<=m;j++)
						for(int k=0;j+k<=y&&i+j+2*k<=m;k++)
							g[l][i+j+2*k]=(g[l][i+j+2*k]+g[l-1][i]*F(x,y-j-k,j,k))%mo;
		}
		printf("%d\n",g[n][m]);
	}
	return 0;
}
