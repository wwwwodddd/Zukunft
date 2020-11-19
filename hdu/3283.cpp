#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int t,n;
char s[100];
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d %s",&n,s);
		printf("%d ",n);
		if(next_permutation(s,s+strlen(s)))
			puts(s);
		else
			puts("BIGGEST");
	}
	return 0;
}
