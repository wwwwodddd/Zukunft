#include<stdio.h>
int n,x,y,z;
int main()
{
	for(;~scanf("%d %d %d %d",&n,&x,&y,&z),n;)
		printf("%d\n",4*n+1+(n+y-x-1)%n+(n+y-z-1)%n);
	return 0;
}
