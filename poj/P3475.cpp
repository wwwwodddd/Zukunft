#include<stdio.h>
#include<math.h>
int min(int a,int b)
{
	return a<b?a:b;
}
int F(int a,int b,int c,int d)
{
	double x=log(1.0*c/a)/log(2.0);
	double y=log(1.0*d/b)/log(2.0);
	x=x<0?0:ceil(x);
	y=y<0?0:ceil(y);
	return x+y;
}
int main()
{
	int a,b,c,d;
	while(scanf("%d %d %d %d",&a,&b,&c,&d)+1)
		printf("%d\n",min(F(a,b,c,d),F(a,b,d,c)));
	return 0;
}