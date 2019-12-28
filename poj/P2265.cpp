#include<stdio.h>
#include<math.h>
#define F for(i=0;i<p&&t;i++,t--)
int n,t,p,x,y,i;
int main()
{
	while(scanf("%d",&n)+1)
	{
		p=(int)(sqrt(12*n-3.0)-3)/6;
		t=n-(3*p*p+3*p+1);
		x=p;
		y=0;
		p++;
		while(t)
		{
			x++;
			F x--,y++;
			F x--;
			F y--;
			F x++,y--;
			F x++;
			F y++;
		}
		printf("%d %d\n",x,y);
	}
	return 0;
}

