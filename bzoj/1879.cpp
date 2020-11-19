#include<stdio.h>
#include<iostream>
#include<string.h>
#define C(x) __builtin_popcount(x)
using namespace std;
int g[60][26],f[60][32780];
char s[20][60];
int t,n,q,l,mo=1000003;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d %d",&n,&q);
		for(int i=0;i<n;i++)
			scanf("%s",s[i]);
		l=strlen(s[0]);
		memset(g,0,sizeof g);
		for(int i='a';i<='z';i++)
			for(int j=0;j<l;j++)
				for(int k=0;k<n;k++)
					if(s[k][j]==i||s[k][j]=='?')
						g[j][i-'a']|=1<<k;
		memset(f,0,sizeof f);
		f[0][(1<<n)-1]=1;
		int z=0;
		for(int i=0;i<l;i++)
			for(int j=0;j<1<<n;j++)
				if(C(j)>=q&&f[i][j])
					for(int k=0;k<26;k++)
						f[i+1][j&g[i][k]]=(f[i+1][j&g[i][k]]+f[i][j])%mo;
		for(int i=0;i<1<<n;i++)
			if(C(i)==q)
				z=(z+f[l][i])%mo;
		printf("%d\n",z);
	}
	return 0;	
}
