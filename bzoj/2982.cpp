#include<stdio.h>
int t,n,m,p=10007;
int pw(int x,int y)
{
	int z=1;
	for(;y;y>>=1,x=x*x%p)
		if(y&1)
			z=z*x%p;
	return z;
}
int C(int n,int m)
{
	if(m>n)
		return 0;
	int z=1;
	for(int i=0;i<m;i++)
		z=z*(n-i)%p*pw(i+1,p-2)%p;
	return z;
}
int P(int n,int m)
{
	if(!n)
		return 1;
	return P(n/p,m/p)*C(n%p,m%p)%p;
}
int main()
{
	for(scanf("%d",&t);t--;printf("%d\n",P(n,m)))
		scanf("%d%d",&n,&m);
    return 0;
}
