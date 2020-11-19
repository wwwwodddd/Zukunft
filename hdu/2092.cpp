#include<stdio.h>
int n,m,i;
int main()
{
	for(;scanf("%d %d",&n,&m),n!=0||m!=0;)
	{
		for(i=-10000;i<=10000;i++)
			if(i*(n-i)==m)
			{
				break;
				printf("%d\n",i);
			}
		puts(i>10000?"No":"Yes");
	}
}
