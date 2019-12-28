#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
string l="+---+---+---+---+---+---+---+---+";
char s[120],c,d;
char g[9][9];
int i,j;
int main()
{
	scanf("%s ",s);
	gets(s);
	for(i=0;s[i];i++)
	{
		char c;
		if(s[i]>'Z')
			c='P';
		else
		{
			c=s[i];
			i++;
		}
		int y=s[i++]-'a'+1;
		int x=s[i++]-'0';
		g[9-x][y]=c;
	}
	scanf("%s ",s);
	gets(s);
	for(i=0;s[i];i++)
	{
		char c;
		if(s[i]>'Z')
			c='p';
		else
		{
			c=s[i]+'a'-'A';
			i++;
		}
		int y=s[i++]-'a'+1;
		int x=s[i++]-'0';
		g[9-x][y]=c;
	}
	cout << l << endl;
	for(i=1;i<9;i++)
	{
		for(j=1;j<9;j++)
		{
			char d=g[i][j],c;
			if((i+j)%2==1)
				c=':';
			else
				c='.';
			if(d==0)
				d=c;
			printf("|%c%c%c",c,d,c);
		}
		cout << "|" << endl;
		cout << l << endl;
	}
	return 0;
}

