#include<stdio.h>
#include<string.h>
int a[257][257];
int b[257][257];
int t,k,n,p=1000000007;
int C(int x,int y)
{
	if(x&y)
		return 0;
	if(x+y==0)
		return 2;
	int z=255^x^y;
	if(z%3==0)
	{
		z/=3;
		if((z&z<<1)==0)
			return 1;
		z*=3;
	}
	z=z/2+(z%2)*128;
	if(z%3==0)
	{
		z/=3;
		if((z&z<<1)==0)
			return 1;
		z*=3;
	}
	return 0;
}
void mul(int a[257][257],int b[257][257],int c[257][257])
{
	int _[257][257]={};
	for(int i=0;i<256;i++)
		for(int k=0;k<256;k++)
			if(a[i][k])
				for(int j=0;j<256;j++)
					if(b[k][j])
						_[i][j]=(_[i][j]+(long long)a[i][k]*b[k][j])%p;
	memcpy(c,_,sizeof _);
}
int main()
{
	for(scanf("%d",&t);t--;)
	{
		memset(a,0,sizeof a);
		a[0][0]=1;
		for(int i=0;i<256;i++)
			for(int j=0;j<256;j++)
				b[i][j]=C(i,j);
		scanf("%d",&n);
		for(;n;n>>=1)
		{
			if(n&1)
				mul(a,b,a);
			mul(b,b,b);
		}
		printf("Case %d: %d\n",++k,a[0][0]);
	}
	return 0;
}
