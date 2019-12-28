#include<stdio.h>
#include<string.h>
char c[32000];
int i,j,k;
int l,sum,min;
int change(char x)
{
	if(x>='0'&&x<='9')
		return x-'0';
	if(x>='A'&&x<='Z')
		return 10+x-'A';
	if(x>='a'&&x<='z')
		return 36+x-'a';
}
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	while(scanf("%s",c)!=EOF)
	{
		sum=min=0;
		l=strlen(c);
		for(i=0;i<l;i++)
		{
			sum+=change(c[i]);
			min=max(min,change(c[i]));
		}
		for(i=min;i<62;i++)
			if(sum%i==0)
				break;
		if(i>=62)
			printf("such number is impossible!\n");
		else
			printf("%d\n",i+1);
	}
	return 0;
}