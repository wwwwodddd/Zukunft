#include<stdio.h>
long long p[31];
int t,x;
int main()
{
	for(int i=p[0]=1;i<31;i++)
		p[i]=p[i-1]*3;
	for(scanf("%d",&t);t--;)
		scanf("%d",&x),printf("%I64d\n",p[x]);
}
