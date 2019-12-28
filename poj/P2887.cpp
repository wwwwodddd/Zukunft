#include<stdio.h>
#include<string.h>
char s[1003000],o[20],c[2020];
int p[2020],pc,n,x,y;
int main()
{
	scanf("%s",s);
	for(scanf("%d",&n);n--;)
	{
		scanf("%s",o);
		if(*o=='I')
		{
			scanf("%s %d",o,p+pc);
			p[pc]--;
			for(int i=0;i<pc;i++)
				if(p[i]>=p[pc])
					p[i]++;
			c[pc++]=*o;
		}
		else
		{
			y=0;
			scanf("%d",&x);
			x--;
			int i;
			for(i=0;i<pc;i++)
				if(p[i]==x)
					break;
				else if(p[i]<x)
					y++;
			printf("%c\n",i==pc?s[x-y]:c[i]);
		}
	}
	return 0;
}
