//DNF
#include<stdio.h>
int P(int x)
{
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			return 0;
	return 1;
}
int z,x,s,m;
int main()
{
	while(~scanf("%d %d",&s,&m))
	{
		z=1;
		for(int i=2;i<=s;i++)
			if(P(i))
			{
				for(x=1;x*i<=s;x*=i)
					;
				z=z*x%m;
			}
		printf("%d\n",z);
	}
	return 0;
}

