#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char f[60][60][60];
char g[60][60];
char t[60][3];
char s[60];
int n,m;
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%s",s);
		g[s[0]-'A'][s[3]-'a']=1;
	}
	for(int i=0;i<m;i++)
	{
		scanf("%s",s);
		t[i][0]=s[0]-'A';
		t[i][1]=s[3]-'A';
		t[i][2]=s[4]-'A';
	}
	while(~scanf("%s",s))
	{
		memset(f,0,sizeof f);
		int l=strlen(s);
		for(int i=0;i<l;i++)
			for(int j=0;j<26;j++)
				f[i][i][j]=g[j][s[i]-'a'];
		for(int o=1;o<l;o++)
			for(int i=0;i<l-o;i++)
				for(int j=i;j<i+o;j++)
					for(int k=0;k<m;k++)
						f[i][i+o][t[k][0]]|=f[i][j][t[k][1]]&&f[j+1][i+o][t[k][2]];
		puts(f[0][l-1][18]?"YES":"NO");
	}
	return 0;
}
