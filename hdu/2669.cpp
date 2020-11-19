#include<stdio.h>
typedef long long ll;
ll gcd(ll a,ll b,ll &x,ll &y)
{
	if(!b)
		return x=1,y=0,a;
	ll g=gcd(b,a%b,y,x);
	y-=a/b*x;
	return g;
}
int main()
{
	ll a,b,x,y,g;
	while(~scanf("%I64d%I64d",&a,&b))
	{
		g=gcd(a,b,x,y);
		if(g>1)
		{
			puts("sorry");
			continue;
		}
		while(x<0)
			x+=b,y-=a;
		while(x>=b)
			x-=b,y+=a;
		printf("%I64d %I64d\n",x,y);
	}
	return 0;
}
