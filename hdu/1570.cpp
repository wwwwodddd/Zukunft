#include<stdio.h>
int f[30],t,x,y;
char s[30];
int main()
{
	for(int i=f[0]=1;i<=10;i++)
		f[i]=f[i-1]*i;
	for(scanf("%d",&t);t--;)
	{
		scanf("%s %d %d",s,&x,&y);
		if(*s=='A')
			printf("%d\n",f[x]/f[x-y]);
		else
			printf("%d\n",f[x]/f[y]/f[x-y]);
	}
	return 0;
}
