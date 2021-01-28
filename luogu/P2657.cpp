#include <bits/stdc++.h>
using namespace std;
int f[15][15];
int a[15];
int F(int x)
{
	int i,j,k;
	int re=0;
	int c = 0;
	memset(a,0,sizeof(a));
	while(x)
	{
		a[++c]=x%10;
		x/=10;
	}

	// a[1] ... a[c]
	for(i=1;i<c;i++)
		for(j=1;j<10;j++)
			re+=f[i][j];
	for(i=1;i<a[c];i++)
		re+=f[c][i];
	for(i=c-1;i>0;i--)
	{
		for(j=0;j<a[i];j++)
			if (abs(j-a[i+1]) >= 2)
			{
				re+=f[i][j];
			}
		if(abs(a[i]-a[i+1])<2)
			break;
	}
	return re;
}
int main()
{
	int i,j,k,x,y;
	for (int i = 0; i < 10; i++)
	{
		f[1][i]=1;
	}
	for (int i = 2; i < 11; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				if(abs(j-k) >= 2)
				{
					f[i][j]+=f[i-1][k];
				}
			}
		}
	}
	scanf("%d%d", &x, &y);
	printf("%d\n", F(y + 1) - F(x));
	return 0;
}