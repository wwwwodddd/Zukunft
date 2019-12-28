#include<stdio.h>
char s[40];
int n,t,k;
int SK(int x)
{
	if(x>=n)
		return 0;
	if(s[x]=='0')
		return SK(x+1);
	else
		return (1<<(n-x))-1-SK(x+1);
}
int main(void)
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %s",&n,s);
		printf("Poslanec %d se posadi na sedadlo cislo %d.\n",++k,1+SK(0));
	}
	return 0;
}