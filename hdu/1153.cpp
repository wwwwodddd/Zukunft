#include<stdio.h>
#include<string.h>
char s[100020];
int n;
int main()
{
	for(;scanf("%d",&n),n;)
	{
		if(n==2)
		{
			puts("Impossible");
			continue;
		}
		memset(s+1,'1',n-1);
		s[n]=0;
		for(long long i=1;i<n;i++)
			s[i*i%n]='0';
		puts(s+1);
	}
	return 0;
}
