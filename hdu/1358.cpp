#include<stdio.h>
#include<string.h>
char s[1000020];
int p[1000020];
int n,k;
int main()
{
	while(scanf("%d %s",&n,s+1),n)
	{
		printf("Test case #%d\n",++k);
		for(int i=2,j=0;i<=n;i++)
		{
			while(j&&s[i]!=s[j+1])
				j=p[j];
			if(s[i]==s[j+1])
				j++;
			p[i]=j;
			if(p[i]&&i%(i-p[i])==0)
				printf("%d %d\n",i,i/(i-p[i]));
		}
		puts("");
	}
}
