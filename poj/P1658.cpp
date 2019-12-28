#include<stdio.h>
int a,b,c,d,t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
	scanf("%d %d %d %d",&a,&b,&c,&d);
	if(b*2==a+c&&c*2==b+d)
		printf("%d %d %d %d %d\n",a,b,c,d,c+c-a);		
	else if(b*b==a*c&&c*c==b*d)
		printf("%d %d %d %d %d\n",a,b,c,d,c*c/a);
	}
	return 0;
}