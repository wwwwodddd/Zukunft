#include<stdio.h>
int i,x;
char ch;
char p[26];
int main()
{
	while((ch=getchar())!=EOF)
		if(ch>='A'&&ch<='Z')
			p[ch-'A']++;
	for(i=0;i<26;i++)
		if(p[i]>x)
			x=p[i];
	while(x--)
	{
		int s;
		for(i=0;i<26;i++)
			if(p[i]>x)
				s=i;
		for(i=0;i<s;i++)
			printf("%s",p[i]>x?"* ":"  ");
		printf("*\n");
	}
	for(i=0;i<25;i++)
		printf("%c ",i+'A');
	printf("Z\n");
	return 0;
}
