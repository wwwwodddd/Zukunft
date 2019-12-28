#include<iostream>
#include<math.h>
using namespace std;
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	double a;
	int l;
	while(cin>>a>>l)
	{
		int x=1,y=1,cx=x,cy=y;
		double d=10000;
		while(x<=l&&y<=l)
		{
			double D=abs(a-(double)x/y);
			if(D<d)
			{
				cy=y;
				cx=x;
				d=D;
			}
			if(x>a*y)
				y++;
			else
				x++;
		}
		printf("%d %d\n",cx/gcd(cx,cy),cy/gcd(cx,cy));
	}
	return 0;
}

