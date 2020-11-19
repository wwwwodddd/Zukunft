#include<stdio.h>
int F(int x)
{
	if(x==0)
		return 1;
	return x*F(x-1);
}
double e;
int i;
int main()
{
	printf("n e\n- -----------\n");
	for(i=0;i<10;i++)
	{
		e+=1.0/F(i);
		printf("%d ",i);
		if(i==8)
			printf("%.9f\n",e);
		else
			printf("%.10g\n",e);
	}
	return 0;
}