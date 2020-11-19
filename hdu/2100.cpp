#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char sa[300],sb[300];
int la,lb,l;
int main()
{
	while(~scanf("%s %s",sa,sb))
	{
		la=strlen(sa);
		reverse(sa,sa+la);
		lb=strlen(sb);
		reverse(sb,sb+lb);
		for(int i=0;i<la;i++)
			sa[i]-='A';
		for(int i=0;i<lb;i++)
			sa[i]+=sb[i]-'A';
		for(int i=0;i<250;i++)
			if(sa[i]>=26)
				sa[i]-=26,sa[i+1]++;
		l=250;
		while(sa[l]==0&&l>0)
			l--;
		for(int i=l;i>=0;i--)
			printf("%c",sa[i]+'A');
		puts("");
		memset(sa,0,sizeof sa);
		memset(sb,0,sizeof sb);
	}
}
