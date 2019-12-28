#include<stdio.h>
#include<math.h>
long double a,p,b,i,j;
int d,l;
inline long double sqr(long double i)
{
	return i * i;
}
long double t[]={1,1e-1,1e-2,1e-3,1e-4,1e-5,1e-6,1e-7,1e-8,1e-9,1e-10};
int main()
{
	p=t[l];
	b=p*d;
	for (a=1;;a++)
	{
		i=(long long)sqr(a+b)+1;
		j=sqr(a+b+p);
		if (j>i)
			break;
	printf("%I64d\n",(long long)i);
	}
return 0;
}