#include<stdio.h>
#include<string.h>
char s[120];
int c[120];
int i,l,k,t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(c,0,sizeof c);
		while(scanf("%s",s),*s!='0'||s[1])
		{
			l=strlen(s);
			for(i=0;i<l;i++)
				c[i]+=s[l-i-1]-'0';
		}
		for(i=0;i<110;i++)
		{
			c[i+1]+=c[i]/10;
			c[i]%=10;
		}
		k=119;
		while(!c[k]&&k)
			k--;
		for(i=k;i>=0;i--)
			printf("%d",c[i]);
		puts("");
		if(t)
			puts("");
	}
	return 0;
}
