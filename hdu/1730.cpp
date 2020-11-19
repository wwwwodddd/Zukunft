#include<stdio.h>
#include<stdlib.h>
int n,m,x,y,z;
int main()
{
	while(~scanf("%d %d",&n,&m))
	{
		for(int i=z=0;i<n;i++)
			scanf("%d %d",&x,&y),z^=abs(y-x)-1;
		puts(z?"I WIN!":"BAD LUCK!");
	}
}
