#include<stdio.h>
#include<string>
char s[1000020],l;
int j,t,f,z;
int main()
{
	while(scanf("%s",&s)&&s[0]!='0')
	{
		l=s[strlen(s)-1];
		f=0;
		for(j=strlen(s)-2;j>=0;j--) 
		{
			z=s[j]-l;
			if(f+z<0)
				s[j]='0'+f+z+10,f=-1;
			else
				s[j]='0'+f+z,f=0;
			l=s[j];
		}
		printf("%d. %s\n",++t,s[0]!='0'?s:"IMPOSSIBLE");
	}
	return 0;
}