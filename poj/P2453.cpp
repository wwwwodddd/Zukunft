#include<stdio.h>
int n,m,x,y;
int i,j,t;
int main()
{
	while(scanf("%d",&n)&&n!=0)
	{
		m=n;
		t=0;
		for(i=0;i<32;i++)
			if(((n>>i)&3)==1)
				break;
		n=((n>>i)^3)<<i;
		for(j=0;j<i;j++)
			if(((m>>j)&1)==1)
				t++;
		x=(0xffffffff<<t);
		y=~x;
		n=n|y;
		printf("%d\n",n);
	}		
	return 0;	
}
