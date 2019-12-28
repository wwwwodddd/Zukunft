#include<stdio.h>
#include<string.h>
int f[12][30];
char s[12];
int main()
{
	int i,j,k,l;
	int ans;
	for(i=0;i<27;i++)
		f[1][i]=1;
	for(i=2;i<11;i++)
		for(j=0;j<27;j++)
			for(k=j+1;k<27;k++)
				f[i][j]+=f[i-1][k];
	while(scanf("%s",s+1)!=EOF)
	{
		ans=0;
		l=strlen(s+1);
		for(i=1;i<l;i++)
			if(s[i]>=s[i+1])
			{
				printf("0\n");
				goto N;
			}
		for(i=1;i<=l;i++)
			s[i]-='a'-1;
		for(i=1;i<=l;i++)
			ans+=f[i][0];
		for(i=1;i<=l;i++)
		{
			for(j=s[i-1]+1;j<s[i];j++)
				ans+=f[l-i+1][j];
		}
		printf("%d\n",ans);
		memset(s,0,sizeof(s));
	N:;
	}
	return 0;
}