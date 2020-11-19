#include<stdio.h>
#include<algorithm>
using namespace std;
int i,n;
char s[100020];
int main()
{
	for(scanf("%d",&n),gets(s);n--;)
	{
		gets(s);
		for(int i=0,j;s[i];i=j+1)
		{
			for(j=i;s[j]!=' '&&s[j];j++)
				;
			reverse(s+i,s+j);
		}
		puts(s);
	}
	return 0;
}
