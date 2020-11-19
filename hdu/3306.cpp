#include<stdio.h>
int p=10007,n,x,y;
int mul(int a[4][4],int b[4][4],int c[4][4])
{
	int _[4][4]={};
	for(int i=0;i<4;i++)
		for(int k=0;k<4;k++)
			if(a[i][k])
				for(int j=0;j<4;j++)
					_[i][j]+=a[i][k]*b[k][j];
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			c[i][j]=_[i][j]%p;
}
int main()
{
	while(~scanf("%d %d %d",&n,&x,&y))
	{
		x%=p,y%=p;
		int a[4][4]={1,1,1,0};
		int b[4][4]={x*x%p,1,x,0,y*y%p,0,0,1,2*x*y%p,0,y,0,0,0,0,1};
		for(n++;n;n>>=1)
		{
			if(n&1)
				mul(a,b,a);
			mul(b,b,b);
		}
		printf("%d\n",a[0][3]);
	}
	return 0;
}
