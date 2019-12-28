#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	unsigned int n,x,y,o;
	while(scanf("%x,%d,%d",&n,&x,&y)!=EOF)
	{
	o=~(1<<x);
	n&=o;
	o=~(1<<(y-2));
	n&=o;
	o=(3<<y-1);
	n|=o;
	printf("%x",n);
	}
return 0;
}