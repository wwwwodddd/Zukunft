#include<iostream>
#include<math.h>
using namespace std;
long long n;
long long ans[100000],c[100000];
long long i,j,k,cnt,a,p;
int main()
{
	while(scanf("%I64d",&n)!=EOF)
	{
		j=(long long)pow(3.0*n,1.0/3)-1;
		cnt=0;
		for(k=j;k>=0;k--)
		{
			a=(long long)((-k+sqrt(k*k-2.0*k*(2.0*k+1)/3+4.0*n/(k+1)))/2);
			p=(k+1)*(a*a*6+a*k*6+k*(k*2+1));
			if(p==n*6)
			{
				ans[cnt]=a;
				c[cnt]=k;
				cnt++;
			}
		}
		printf("%I64d\n",cnt);
		for(i=0;i<cnt;i++)
		{
			printf("%I64d",c[i]+1);
			for(j=0;j<=c[i];j++)
				printf(" %I64d",(ans[i]+j));
			printf("\n");
		}
	}
	return 0;
}
