#include<stdio.h>
#include<string.h>
int a[62][62],b[62][62],c[62][62];
int n,o,m,i,j,k;
void matrixmul(int x[][62],int y[][62],int n)
{

	memset(c,0,sizeof(c));
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			for(k=1;k<=n;k++)
				c[i][j]+=(x[i][k]*y[k][j])%m;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			x[i][j]=c[i][j]%m;
}
void matrixpow(int x[][62],int n,int k)  //n½×·½ÕóµÄk´ÎÃÝ
{
	for(int i=1;i<=2*n;i++)
		b[i][i]=1;
	while(k)
	{
		if(k&1)
			matrixmul(b,x,n);
		k>>=1;
		matrixmul(x,x,n);
	}
}
int main()
{
	scanf("%d%d%d",&n,&o,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	for(i=1;i<=n;i++)
		a[n+i][n+i]=a[i][n+i]=1;
	matrixpow(a,2*n,o+1);
	for(i=1;i<=n;i++)
		b[i][n+i]=(b[i][n+i]+m-1)%m;
	for(i=1;i<=n;i++)
	{
		for(j=n+1;j<=2*n;j++)
			printf("%d ",b[i][j]);
		printf("\n",b[i][j]);
	}
	return 0;
}