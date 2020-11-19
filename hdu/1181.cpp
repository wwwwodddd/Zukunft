#include<stdio.h>
#include<string.h>
char s[1020];
int g[30][30];
int main()
{
	while(1)
	{
		memset(g,0,sizeof g); 
		*s=0;
		for(;~scanf("%s",s)&&*s!='0';)
			g[s[0]-'a'][s[strlen(s)-1]-'a']=1;
		if(!*s)
			break;
		for(int k=0;k<26;k++)
			for(int i=0;i<26;i++)
				for(int j=0;j<26;j++)
					g[i][j]|=g[i][k]&g[k][j];
		puts(g[1][12]?"Yes.":"No.");
	}
	return 0;
}
