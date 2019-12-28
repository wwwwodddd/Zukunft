#include<stdio.h>
#include<string.h>
double f[120][120];
int g[120];
int n,t,l,b,x;
void add(int x,int y,double z)
{
	if(g[y]==1)
		f[x+1][y]+=z;
	else if(g[y]==2)
		f[x][0]+=z;
	else
		f[x][y]+=z;
}
int main()
{
	while(scanf("%d %d %d %d",&n,&t,&l,&b),n)
	{
		memset(f,0,sizeof f);
		memset(g,0,sizeof g);
		f[0][0]=1;
		for(;l--;)
			scanf("%d",&x),g[x]=1;
		for(;b--;)
			scanf("%d",&x),g[x]=2;
		for(int i=0;i<t;i++)
		{
			for(int j=0,k,c;j<n;j++)
			{
				double t=f[i][j]/6;
				for(k=j+1,c=6;c&&k<n;k++,c--)
					add(i+1,k,t);
				for(;c;k--,c--)
					add(i+1,k,t);
			}
			f[i+1][n]+=f[i][n];
		}
		printf("%.6f\n",f[t][n]);
	}
	return 0;
}
