#include<stdio.h>
#include<string.h>
using namespace std;
char s[1020];
int a,b;
int main()
{
	while(~scanf("%s",s))
	{
		a=b=0;
		for(int i=0;s[i];i++)
			if(s[i]>='0'&&s[i]<='9')
				a=a*10+s[i]-'0';
		if(*s=='-')
			a=-a;
		scanf("%s",s);
		for(int i=0;s[i];i++)
			if(s[i]>='0'&&s[i]<='9')
				b=b*10+s[i]-'0';
		if(*s=='-')
			b=-b;
		printf("%d\n",a+b);
	}
}
