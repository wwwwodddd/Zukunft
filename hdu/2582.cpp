#include<stdio.h>
long long s[1000020];
int main()
{
	for(int i=2;i<=1000000;i++)
		if(!s[i])
		{
			for(int j=i;j<=1000000;j+=i)
				s[j]=1;
			for(long long j=i;j<=1000000;j*=i)
				s[j]=i;
		}
	s[2]=0;
	for(int i=3;i<=1000000;i++)
		s[i]+=s[i-1];
	for(int x;~scanf("%d",&x);)
		printf("%I64d\n",s[x]);
	return 0;
}
