#include<stdio.h>
long long f[40]={1};
long long p[40]={1};
int n,m;
int main()
{
	for(int i=2;i<30;i++)
		f[i]=(f[i-1]+f[i-2])*(i-1);
	for(int i=1;i<30;i++)
		p[i]=p[i-1]*i;
	for(scanf("%*d");~scanf("%d %d",&n,&m);)
		printf("%I64d\n",p[n]/p[m]/p[n-m]*f[m]);
}
