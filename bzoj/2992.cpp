#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,k,z,a[60],f[60][2],p=1000000003;
void inc(int&x,int y)
{
	x+=y;
	if(x>=p)
		x-=p;
}
int main()
{
	for(;scanf("%d%d",&n,&k),n;)
	{
		for(int i=z=0;i<n;i++)
			scanf("%d",a+i);
		for(;;)
		{
			sort(a,a+n);
			if(a[n-1]==0)
				break;
			int t=1;
			for(;2*t<=a[n-1];t*=2)
				;
			if(k>=2*t)
				break;
			memset(f,0,sizeof f);
			f[0][0]=1;
			for(int i=0;i<n-1;i++)
				for(int j=0;j<2;j++)
				{
					inc(f[i+1][j],(long long)f[i][j]*min(t,a[i]+1)%p);
					inc(f[i+1][j^1],(long long)f[i][j]*max(0,a[i]+1-t)%p);
				}
			if(k<t)
				inc(z,f[n-1][0]);
			else
				inc(z,f[n-1][1]);
			a[n-1]-=t;
			k^=t;
		}
		if(k==0)
			z++;
		printf("%d\n",z);
	}
	return 0;
}
