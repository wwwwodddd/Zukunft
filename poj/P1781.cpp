#include<stdio.h>
int a,b,e[8]={1,10,100,1000,10000,100000,1000000,10000000};
int J(int x)
{
	if(x==1)
		return 1;
	if(x&1)
		return 2*J(x>>1)+1;
	else
		return 2*J(x>>1)-1;
}
int main()
{
	while(scanf("%de%d",&a,&b)&&a*e[b]!=0)
		printf("%d\n",J(a*e[b]));
	return 0;
}