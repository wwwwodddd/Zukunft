#include<stdio.h>
int x1,y1,x2,y2,x3,y3,p,q;
int abs(int x)
{
	return x>0?x:-x;
}
int gcd(int x,int y)
{
	return y==0?x:gcd(y,x%y);
}
int L(int x1,int y1,int x2,int y2)
{
	if(x1==x2)
		return abs(y1-y2);
	if(y1==y2)
		return abs(x1-x2);
	return gcd(abs(x1-x2),abs(y1-y2));
}
int main()
{
	while(scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3)&&x1|x2|x3|y1|y2|y3)
	{
		p=abs(x1*y2+x2*y3+x3*y1-x2*y1-x3*y2-x1*y3);
		q=L(x1,y1,x2,y2)+L(x1,y1,x3,y3)+L(x2,y2,x3,y3);
		printf("%d\n",p/2+1-q/2);
	}
	return 0;
}