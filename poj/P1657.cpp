#include<iostream>
using namespace std;
char a[10];
int sx,sy,ex,ey,t;
int k,q,r,b,c,d;
int main()
{
scanf("%d",&t);
getchar();
while(t--)
	{
	k=q=r=b=2;
	scanf("%s",a);
	scanf("%s",a+3);
	sx=a[0]-'a'+1;
	sy=a[1]-'0';
	ex=a[3]-'a'+1;
	ey=a[4]-'0';
	if(sx==ex||sy==ey)
		{
		r>1?r=1:0;
		q>1?q=1:0;
		}
	if(sx+sy==ex+ey||sx-sy==ex-ey)
		{
		b>1?b=1:0;
		q>1?q=1:0;
		}
	c=sx-ex;
	d=sy-ey;
	c=c<0?-c:c;
	d=d<0?-d:d;
	k=c>d?c:d;
	((((sx^sy)^(ex^ey))&1)==0)?0:b=64;
	if(sx==ex&&sy==ey)
	printf("0 0 0 0\n");
	else if(b!=64)
	printf("%d %d %d %d\n",k,q,r,b);
	else
	printf("%d %d %d Inf\n",k,q,r);
	}
return 0;
}