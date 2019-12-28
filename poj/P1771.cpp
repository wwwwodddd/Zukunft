#include<iostream>
using namespace std;
int n,f[40],c[40][40],z[40][40];
int L(int x,int l,int r)
{
	return l>r?0:max(abs(x-f[l]),abs(x-f[r]))*20;
}
int S(int i,int j,int k)
{
	if(k==0)
		return 0;
	return c[i+1][k]+4+((j==k||i==1)?0:10);
}
void C()
{
	int i,j,k,p;
	for(j=1;j<=n;j++)
		c[f[1]][j]=L(f[1],1,j);
	for(i=f[1]-1;i>0;i--)
		for(j=1;j<=n;j++)
		{
			c[i][j]=0x3fffffff;
			for(k=0;k<=j;k++)
			{
				p=max(S(i,j,k),L(i,k+1,j));
				if(c[i][j]>p)
				{
					c[i][j]=p;
					z[i][j]=k;
				}
			}
		}
	printf("%d\n",c[1][n]);
}
void R()
{
	int v[40],k=0,j=z[1][n];
	for(int i=2;i<=f[1]&&j;i++)
		if(z[i][j]!=j)
		{
			v[k++]=i;
			j=z[i][j];
		}
	printf("%d ",k);
	for(int i=0;i<k;i++)
		printf("%d ",v[i]);
	printf("\n");
}
int main()
{
	while(scanf("%d",&n)&&n)
	{
		for(int i=n;i>0;i--)
			scanf("%d",&f[i]);
		memset(c,0,sizeof(c));
		memset(z,0,sizeof(z));
		C();
		R();
	}
	return 0;
}
