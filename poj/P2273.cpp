#include<stdio.h>
char s;
int r,c,a[1000],i;
int main()
{
	while(scanf("%c%d%c%d",&s,&c,&s,&r)&&r+c)
	{
		getchar();
		i=0;
		while(r)
		{
			a[i]=r%26;
			if(!a[i])
			{
				a[i]=26;
				r--;
			}
			r/=26;
			i++;
		}
		for(i--;i>=0;i--)
			printf("%c",a[i]+'A'-1);
		printf("%d\n",c);
	}
	return 0;
}

