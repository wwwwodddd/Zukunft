#include<stdio.h>
#include<string.h>
char c[30];
int t[30];
int s[30];
int n,i,ans;
int dfs(int x)
{
	if(t[x]==1)
		return 0;
	else
	{
		t[x]=1;
		return dfs(c[x]-'A')+1;
	}
}
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		ans=0;
		memset(s,0,sizeof(s));
		memset(t,0,sizeof(t));
		scanf("%s",c);
		for(i=0;i<26;i++)
			if(!t[i])
				s[dfs(i)]++;
		for(i=0;i<27;i+=2)
			ans|=s[i];
		printf("%s\n",ans&1?"No":"Yes");
	}
	return 0;
}
