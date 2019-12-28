#include<stdio.h>
int x,y,t,l,r,i,j,k,a,b;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&x,&y, &l, &r);
		for(i=r-1;i>l;i--)
		{
			b=0;
			k=1;
			a=i;
			while(a)
			{
				b+=a%x*k;
				k*=y;
				a/=x;
			}
			if(b%i==0)
				break;
		}
		if(i-l)
			printf("%d\n",i);
		else
			puts("Non-existent.");
	}
	return 0;
}