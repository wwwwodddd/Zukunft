#include<stdio.h>
#include<algorithm>
using namespace std;
char s[20];
int main()
{
	while(scanf("%s",s)+1)
	{
		sort(s,s+3);
		printf("%c %c %c\n",s[0],s[1],s[2]);
	}
	return 0;
}