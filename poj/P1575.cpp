#include<iostream>
#include<string.h>
using namespace std;
char s[50];
int i,sum,a[30],l;
int check()
{
	for(i=0;i<l;i++)
	{
		if(s[i]=='a'||s[i]=='o'||s[i]=='e'||s[i]=='i'||s[i]=='u')
			a[i]=1;
		else
			a[i]=0;
		sum+=a[i];
	}
	if(sum==0)
		return 0;
	if(l>=3)
		sum=a[0]+a[1];
	for(i=2;i<l;i++)
	{
		sum+=a[i];
		if(sum==0||sum==3)
			return 0;
		sum-=a[i-2];
	}
	sum=a[0];
	for(i=1;i<l;i++)
	{
		sum+=a[i];
		if(sum==2&&((s[i]=='a'||s[i]=='i'||s[i]=='u')&&s[i-1]==s[i]))
			return 0;
		if(sum==0&&s[i]==s[i-1])
			return 0;
		sum-=a[i-1];
	}
	return 1;
}
int main()
{
	while(scanf("%s",s)&&strcmp(s,"end")!=0)
	{
		l=strlen(s);
		sum=0;
		printf("<%s> is%s acceptable.\n",s,check()?"":" not");
	}
	return 0;
}
