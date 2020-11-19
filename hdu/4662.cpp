#include<stdio.h>
char s[1000020];
int t,n;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%s",s);
		int z=0;
		for(int i=1;s[i];i++)
			if(s[i]=='M')
			{
				puts("No");
				goto end;
			}
			else if(s[i]=='U')
				z+=3;
			else
				z++;
		if(s[0]=='M'&&(z==1||z%6!=0&&z%2==0))
			puts("Yes");
		else
			puts("No");
		end:;
	}
}
