#include<stdio.h>
#include<vector>
using namespace std;
int P(int x)
{
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			return 0;
	return 1;
}
int n,z,s,ac,a[10020];
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
		if(P(i))
			a[ac++]=i;
	z=ac;
	while(ac-s>1)
	{
		if(a[s]*a[ac-1]<=n)
			s++;
		ac--;
	}
	printf("%d",z-s);
}
