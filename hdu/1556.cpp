#include<stdio.h>
#include<string.h>
int n,x,y;
int s[100020];
int main()
{
	while(scanf("%d",&n),n)
	{
		memset(s,0,sizeof s);
		for(int i=0;i<n;i++)
			scanf("%d%d",&x,&y),s[x]++,s[y+1]--;
		for(int i=1;i<=n;i++)
			printf("%d%c",s[i]+=s[i-1],i<n?' ':'\n');
	}
	return 0;
}
