#include<iostream>
#include<stdio.h>
using namespace std;
int n,m;
char s[60][60];
int F()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(s[i][j]=='0'&&s[i+1][j]=='0'&&s[i][j+1]=='0'&&s[i+1][j+1]=='0')
			{
				s[i][j]=s[i+1][j]=s[i][j+1]=s[i+1][j+1]='1';
				int u=F();
				s[i][j]=s[i+1][j]=s[i][j+1]=s[i+1][j+1]='0';
				if(!u)
					return 1;
			}
	return 0;
}
int main()
{
	while(~scanf("%d %d",&n,&m))
	{
		memset(s,0,sizeof s);
		for(int i=0;i<n;i++)
			scanf("%s",s[i]);
		puts(F()?"Yes":"No");
	}
	return 0;
}
