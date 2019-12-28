#include<stdio.h>
#include<math.h>
int g[250][250],mn[250][250][8],mx[250][250][8];
int n,b,r,h;
int i,j,x,y;
int max(int a,int b,int c,int d)
{
	a=a>b?a:b;
	a=a>c?a:c;
	a=a>d?a:d;
	return a;
}
int min(int a,int b,int c,int d)
{
	a=a<b?a:b;
	a=a<c?a:c;
	a=a<d?a:d;
	return a;
}
void RMQ()
{
	int i,j,k;
	for(i=0;i<n;++i)
		for(j=0;j<n;++j) 
			mx[i][j][0]=mn[i][j][0]=g[i][j];
	for(i=0;i<log((double)n)/log(2.0)-1;i++)
		for(j=0;j<=n-pow(2.0,i)+0.1;j++)
			for(k=0;k<n-pow(2.0,i)+0.1;k++)
			{
				mx[j][k][i+1]=max(mx[j][k][i],mx[j+(1<<(i))][k][i],mx[j][k+(1<<i)][i],mx[j+(1<<i)][k+(1<<i)][i]);
				mn[j][k][i+1]=min(mn[j][k][i],mn[j+(1<<(i))][k][i],mn[j][k+(1<<i)][i],mn[j+(1<<i)][k+(1<<i)][i]);
			}
}
int main()
{
	scanf("%d %d %d",&n,&b,&r);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&g[i][j]);
	RMQ();
	while(r--)
	{
		scanf("%d%d",&x,&y);
		x--;y--;
		h=log((double)b)/log(2.0)+0.1;
		printf("%d\n",max(mx[x][y][h],mx[x+b-(1<<h)][y][h],mx[x][y+b-(1<<h)][h],mx[x+b-(1<<h)][y+b-(1<<h)][h])-min(mn[x][y][h],mn[x+b-(1<<h)][y][h],mn[x][y+b-(1<<h)][h],mn[x+b-(1<<h)][y+b-(1<<h)][h]));
	}
}
