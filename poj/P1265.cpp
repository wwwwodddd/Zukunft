#include<iostream>
using namespace std;
int i,k,t,n,x,y,dx,dy,o,s;
int gcd(int a,int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=o=s=x=y=0;i<n;i++)
		{
			scanf("%d%d",&dx,&dy);
			s+=x*dy-dx*y;
			o+=abs(gcd(dx,dy));
			x+=dx;
			y+=dy;
		}
		printf("Scenario #%d:\n%d %d %.1lf\n\n",++k,(s-o+2)/2,o,s/2.0);
	}
	return 0;
}
