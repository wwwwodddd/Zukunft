#include<stdio.h>
int x,y;
int F(int x,int y)
{
	if(x%y==0||x/y>1)
		return 1;
	return !F(y,x-y);
}
int main()
{
	while(scanf("%d %d",&x,&y),x+y)
	{
		if(x<y)
			x^=y^=x^=y;
		printf("%s wins\n",F(x,y)?"Stan":"Ollie");
	}
	return 0;
}
