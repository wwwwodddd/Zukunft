#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char s[3000];
int t;
int main()
{
	scanf("%d",&t);
	gets(s);
	while(t--)
	{
		gets(s);
		reverse(s,s+strlen(s));
		puts(s);
	}
}
