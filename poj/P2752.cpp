#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
char p[400010];
int a[400010];
int l,m,n,i,j,k,q,ans;
void dfs(int x)
{
if(a[x]==0)
{
printf("%d ",x);
return;
}
dfs(a[x]);
printf("%d ",x);
return;
}
int main()
{
while(scanf("%s",p+1)!=EOF)
	{
	m=strlen(p+1);
	memset(a,0,sizeof(a));
	a[1]=0;
	k=0;
	for(q=2;q<=m;q++)
		{
		while(k>0&&p[k+1]!=p[q])
			k=a[k];
		if(p[k+1]==p[q])
			k++;
		a[q]=k;
		}
	dfs(m);
	printf("\n");
	}
return 0;
}

