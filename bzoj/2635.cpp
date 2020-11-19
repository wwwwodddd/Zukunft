#include <stdio.h>
typedef unsigned long long ull;
int A(ull n)
{
	int re=1;
	while(n!=1)
	{
		if(n&1)
		{
			n=1+n>>1;
			if((n&1)==0)
				re=-re;
		}
		else
		{
			n>>=1;
			re=-re;
		}
	}
	return re;
}
inline bool sgn(ull n)
{
	return (bool)(n&(0x5555555555555555ULL));
}
int S(ull n)
{
	if(n<=1)
		return n==1;
	if(n&1)
		return 2*S(n/4)+A(n);
	else
		return 2*S(n/4);
}
int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int c;
		ull n;
		scanf("%d %llu",&c,&n);
		if(c==1)
			printf("%d\n",A(n));
		else if(c==2)
			puts(sgn(n)?"+":"0");
		else if(c==3)
			printf("%d\n",S(n));
	}
	return 0;
}