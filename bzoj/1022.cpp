#include<stdio.h>
int csc,x,z,i,n,v;
int main()
{
	scanf("%d",&csc);
	while(csc--)
	{
		scanf("%d",&n);
		v=0;
		while(n--)
		{
			scanf("%d",&x);
			z^=x;
			v|=(x>1);
		}
		if(v)
			puts(x?"John":"Brother");
		else
			puts(x?"Brother":"John");
	}
	return 0;
}