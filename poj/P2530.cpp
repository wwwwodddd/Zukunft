#include<stdio.h>
int n,v[30],in[30],g[30][30];
char s[60][60];
using namespace std;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%s",s[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<20;j++)
			if(s[i][j]!='.')
			{
				v[s[i][j]-'A']=1;
				for(int k=i+1;k<n;k++)
					if(s[k][j]!='.')
					{
						if(s[i][j]!=s[k][j])
						{
							if(!g[s[i][j]-'A'][s[k][j]-'A'])
								in[s[i][j]-'A']++;
							g[s[i][j]-'A'][s[k][j]-'A']=1;
						}
						break;
					}
			}
	for(int i=0;i<26;i++)
		for(int j=0;j<26;j++)
			if(!in[j]&&v[j])
			{
				printf("%c",'A'+j);
				v[j]=0;
				for(int k=0;k<26;k++)
					if(g[k][j])
						in[k]--;
				break;
			}
	return 0;
}
