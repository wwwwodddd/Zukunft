#include<stdio.h>
char s[1020];
int a;
int main()
{
	while(~scanf("%s",s))
	{
		a=0;
		for(int i=0;s[i];i++)
			if(s[i]>='0'&&s[i]<='9')
				a=(a*10+s[i]-'0')%9999;
		printf("%d\n",a*(a+1)%9999*(a+2)%9999*(a+3)%9999*2500%9999);
	}
}
