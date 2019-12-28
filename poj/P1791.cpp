#include<iostream>
using namespace std;
#define inf 0x3f3f3f3f
int a,b,c,d,e,f,z;
int main()
{
	while(scanf("%d %d %d %d %d %d",&c,&d,&a,&b,&e,&f),a+b+c+d+e+f)
	{
		z=inf;
		if(a>b)
			swap(a,b);
		if(c>d)
			swap(c,d);
		if(e>f)
			swap(e,f);
		if(a*c<=e&&b*d<=f)
			z=min(z,c*d-1+(e>a*c)+(f>b*d));
		if(min(a*d,b*c)<=e&&max(a*d,b*c)<=f)
			z=min(z,c*d-1+(e>min(a*d,b*c))+(f>max(a*d,b*c)));
		if(z<inf)
			printf("The minimum number of cuts is %d.\n",z);
		else
			puts("The paper is too small.");
	}
	return 0;
}