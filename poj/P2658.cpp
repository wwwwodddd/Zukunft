#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
char s[100];
char w[4][100];
int t,n,m,l,ab,ac,ad,bc,bd,cd;
int main()
{
	for(scanf("%d",&t),gets(s);t--;)
	{
		for(n=0;n<4;n++)
		{
			m=0;
			gets(s);
			l=strlen(s);
			for(int i=l-1;i>=0;i--)
			{
				if(s[i]==' ')
					break;
				if(islower(s[i]))
					s[i]=toupper(s[i]);
				w[n][m++]=s[i];
				if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
					break;
			}
			w[n][m]=0;
		}
		ab=strcmp(w[0],w[1]);
		ac=strcmp(w[0],w[2]);
		ad=strcmp(w[0],w[3]);
		bc=strcmp(w[1],w[2]);
		bd=strcmp(w[1],w[3]);
		cd=strcmp(w[2],w[3]);
		if(!ab)
		{
			if(!ac&&!ad)
				puts("perfect");
			else if(bc&&!cd)
				puts("even");
			else
				puts("free");
		}
		else if(!ac&&!bd)
			puts("cross");
		else if(!ad&&!bc)
			puts("shell");
		else
			puts("free");
	}
	return 0;
}
