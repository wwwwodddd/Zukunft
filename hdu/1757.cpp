#include<stdio.h>
#include<string.h>
int n,p;
long long a[30],b[30],f[30],z;
void mul(long long a[],long long b[],long long c[])
{
	long long _[30];
	memset(_,0,sizeof _);
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			_[i+j]=(_[i+j]+a[i]*b[j])%p;
    for(int i=18;i>9;i--)
            for(int j=0;j<10;j++)
                _[i-10+j]=(_[i-10+j]+_[i]*f[j])%p;
    memset(c,0,sizeof _);
    for(int i=0;i<10;i++)
        c[i]=_[i];
}
int main()
{
	while(~scanf("%d %d",&n,&p))
	{
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		memset(f,0,sizeof f);
		z=0;
		for(int i=9;~i;i--)
			scanf("%d",f+i);
		a[0]=1;
		b[1]=1;
		for(;n;n>>=1)
		{
			if(n&1)
				mul(a,b,a);
			mul(b,b,b);
		}
		for(int i=0;i<10;i++)
			z=(z+i*a[i])%p;
		printf("%d\n",z);
	}
	return 0;
}
