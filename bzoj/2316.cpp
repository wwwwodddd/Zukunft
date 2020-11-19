#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
inline int lowbit(int x){return x&-x;}
int log(int x){return x==1?0:(log(x/2)+1);}
int i,j,n,m,t;
int SG(int x,int y)
{
	return (!x||!y)?log(lowbit(x+y+1)):(x+y);
}
bool v[210];
char s[210];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		memset(v,0,sizeof v);
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			for(j=0;j<m;j++)
				if(s[j]=='T')
					v[SG(i,j)]^=1;
		}
		for(i=0;i<n+m;i++)
			if(v[i])
				break;
		puts(i==n+m?"=_=":"-_-");
	}
	return 0;
}