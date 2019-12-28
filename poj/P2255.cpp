#include<stdio.h>
#include<string.h>
char a[30],b[30];
int l,k;
void dfs(int l,int r)
{
	if(l>r)
		return;
	int p,i;
	for(i=l;i<=r;i++)
		if(a[k]==b[i])
		{
			k++;
			dfs(l,i-1);
			dfs(i+1,r);
			putchar(b[i]);
		}
}
int main()
{
	while(scanf("%s %s",a,b)+1)
	{
		k=0;
		l=strlen(a);
		dfs(0,l-1);
		printf("\n");
	}
	return 0;
}