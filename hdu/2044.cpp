#include<stdio.h>
int n,m;
long long f[60]={0,1};
int main()
{
	for(int i=2;i<55;i++)
		f[i]=f[i-1]+f[i-2];
	for(scanf("%*d");~scanf("%d %d",&n,&m);)
		printf("%I64d\n",f[m-n+1]);
}
