#include<stdio.h>
int i,t,z;
char s[1020];
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%s",s);
		for(i=z=0;s[i];i++)
			if(s[i]=='0')
				z++;
			else if(z>1)
				z--;
			else
				break;
		puts(s[i]||z>1?"No":"Yes");
	}
	return 0;
}
