#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct P
{
    int a[1020],n;
    P()
    {
        memset(a,0,sizeof a),n;
    }
    void print()
    {
        printf("(");
        if(a[n]==1)
            printf("x");
        else if(a[n]==-1)
            printf("-x");
        else
            printf("%dx",a[n]);
        if(n>1)
            printf("^%d",n);
        for(int i=n-1;i>0;i--)
            if(a[i])
            {
                if(a[i]==1)
                    printf("+x");
                else if(a[i]==-1)
                    printf("-x");
                else
                	printf("%+dx",a[i]);
				if(i>1)
					printf("^%d",i);
			}
		printf("%+d",a[0]);
		printf(")");
	}
}f[1020],z[1020];
P operator/(const P&a,const P&b)
{
	P c=a,_;
	_.n=a.n-b.n;
	for(int i=a.n;i>=b.n;i--)
	{
		int k=_.a[i-b.n]=c.a[i]/b.a[b.n];
		for(int j=b.n;j>=0;j--)
			c.a[i-b.n+j]-=k*b.a[j];
	}
	return _;
}
bool operator<(const P&a,const P&b)
{
	if(a.n!=b.n)
		return a.n<b.n;
	for(int i=a.n;i>=0;i--)
		if(abs(a.a[i])!=abs(b.a[i]))
			return abs(a.a[i])<abs(b.a[i]);
		else if(a.a[i]!=b.a[i])
			return a.a[i]<b.a[i];
	return 0;
} 
int main()
{
	for(int i=1;i<=1001;i++)
	{
		f[i].a[i]=1;
		f[i].a[0]=-1;
		f[i].n=i;
		for(int j=1;j<i;j++)
			if(i%j==0)
				f[i]=f[i]/f[j];
	}
	int n,zc;
	while(scanf("%d",&n),n)
	{
		zc=0;
		for(int i=1;i<=n;i++)
			if(n%i==0)
				z[zc++]=f[i];
		sort(z,z+zc);
		for(int i=0;i<zc;i++)
			z[i].print();
		puts("");
	}
	return 0;
}
