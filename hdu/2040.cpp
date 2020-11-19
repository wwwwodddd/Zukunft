#include<stdio.h>
int t,x,y,X,Y;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d %d",&x,&y);
		X=Y=0;
		for(int i=1;i<x;i++)
			if(x%i==0)
				X+=i;
		for(int i=1;i<y;i++)
			if(y%i==0)
				Y+=i;
		puts(X==y&&Y==x?"YES":"NO");
	}
	return 0;
}
