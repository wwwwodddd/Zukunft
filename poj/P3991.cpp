#include<stdio.h>
char s[2020];
int x,y,z;
int main()
{
	for(;scanf("%s",s),*s!='-';)
	{
		x=y=0;
		for(int i=0;s[i];i++)
		{
			if(s[i]=='{')
				y++;
			else if(y)
				y--;
			else
				x++;
		}
		printf("%d. %d\n",++z,(x+1)/2+(y+1)/2);
	}
	return 0;
}
