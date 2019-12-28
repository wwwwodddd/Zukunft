#include<stdio.h>
int a,b,i;
int check(int a,int b)
{
	if(a<b)
		return check(b,a);
	if(b==0)
		return 0;
	if(a/b>=2)
		return 1;
	return check(b,a%b)^1;
}
int main()
{
	while(scanf("%d%d",&a,&b)&&a+b)
		printf("%s wins\n",check(a,b)?"Stan":"Ollie");
}
