#include <stdio.h>
#include <math.h>
__int64 mod_r(__int64 n,__int64 k)
{
	__int64 r=0,a=(__int64)sqrt(1.0*k),b=k/a,i,s,e;
	if(n>k)
		r+=(n-k)*k;
	for(i=a;i>1;i--)
	{
		s=k/i;
		e=k/(i-1);
		if(s>n)
			break;
		if(e>n)
			e=n;
		r+=(k%e+k%(s+1))*(e-s)/2;
	}
	for(i=1;i<=n&&i<=b;i++)
		r+=k%i;
	return r;
}
int main()
{
	__int64 n,k;
	while(scanf("%I64d%I64d",&n,&k)+1)
		printf("%I64d\n",mod_r(n,k));
	return 0;
}