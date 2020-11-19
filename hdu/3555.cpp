#include<stdio.h>
int g[3][10],o;
long long f[19][3],t[19],n;
int main()
{
	g[0][4]=1;
	g[1][4]=1;
	g[1][9]=2;
	for(int i=0;i<10;i++)
		g[2][i]=2;
	f[0][2]=1;
	for(int i=1;i<19;i++)
	{
		f[i][0]=f[i-1][0]*9+f[i-1][1];
		f[i][1]=f[i-1][0]*8+f[i-1][1]+f[i-1][2];
		f[i][2]=f[i-1][2]*10;
	}
	for(int i=t[0]=1;i<19;i++)
		t[i]=t[i-1]*10;
	for(scanf("%d",&o);o--;)
	{
		scanf("%I64d",&n);
		long long z=0;
		int p=0;
		for(int i=18;~i;i--)
		{
			int u=n/t[i]%10;
			for(int j=0;j<u;j++)
				z+=f[i][g[p][j]];
			p=g[p][u];
		}
		if(p==2)
			z++;
		printf("%I64d\n",z);
	}
	return 0;
}
