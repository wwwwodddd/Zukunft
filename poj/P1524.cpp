#include<stdio.h>
int t,x,y;
int scan()
{
	char s[60];
	int _=0;
	scanf("%s",s);
	for(int i=0;s[i];i++)
		if(s[i]=='V')
			_=_*4;
		else if(s[i]=='U')
			_=_*4+1;
		else if(s[i]=='C')
			_=_*4+2;
		else if(s[i]=='D')
			_=_*4+3;
	return _;
}
int main()
{
	char o[5];
	puts("COWCULATIONS OUTPUT");
	for(scanf("%d",&t);t--;)
	{
		int x=scan(),y=scan();
		for(int i=0;i<3;i++)
		{
			scanf("%s",o);
			if(*o=='A')
				y+=x;
			else if(*o=='L')
				y<<=2;
			else if(*o=='R')
				y>>=2;
			y&=0xffff;
		}
		puts(y==scan()?"YES":"NO");
	}
	puts("END OF OUTPUT");
	return 0;
}
