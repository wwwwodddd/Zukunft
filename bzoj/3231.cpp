#include<stdio.h>
#include<string.h>
const int N=16;
int a[N][N],b[N][N],c[N][N],p,T;
long long n,m;
void mul(int a[N][N],int b[N][N],int c[N][N])
{
	int _[N][N]={};
	for(int i=0;i<T;i++)
		for(int k=0;k<T;k++)
			if(a[i][k])
				for(int j=0;j<T;j++)
					_[i][j]=(_[i][j]+(long long)a[i][k]*b[k][j])%p;
	memcpy(c,_,sizeof _);
}
int main()
{
	scanf("%d",&T);
	for(int i=0;i<T;i++)
		scanf("%d",a[0]+i);
	for(int i=1;i<T;i++)
		b[i][i-1]=1;
	b[T][T]=1;
	for(int i=0;i<T;i++)
		scanf("%d",&b[T-i-1][T-1]);
	memcpy(c,b,sizeof c);
	c[0][T]=1;
	scanf("%lld%lld%d",&m,&n,&p),m--,n-=m,T++;
	for(;m;m>>=1,mul(b,b,b))
		if(m&1)
			mul(a,b,a);
	for(;n;n>>=1,mul(c,c,c))
		if(n&1)
			mul(a,c,a);
	printf("%d\n",a[0][T-1]);
	return 0;
}
