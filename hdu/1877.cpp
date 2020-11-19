#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int m,a,b;
char s[1000];
int main()
{
	for(;scanf("%d",&m),m;)
	{
		scanf("%d %d",&a,&b);
		itoa(a+b,s,m);
		puts(s);
	}
}
