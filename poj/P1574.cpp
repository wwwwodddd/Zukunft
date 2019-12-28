#include<stdio.h>
#include<iostream>
using namespace std;
int a[6][3];
int t[6],c[8];
char s[6];
int ans,re;
void R(int *p)
{
	swap(p[0],p[1]);
	swap(p[0],p[2]);
	return;
}
void dfs(int x)
{
	if(x==7&&a[c[1]][0]==a[c[6]][1])
			ans=max(ans,re);
	int i,j,k;
	for(i=6;i--;)
		if(t[i]==0)
			for(j=3;j--;)
			{
				R(a[i]);
				if(a[i][0]!=a[c[x-1]][1]&&x!=1)
					continue;
				c[x]=i;
				t[i]=1;
				re+=a[i][2];
				dfs(x+1);
				t[i]=0;
				re-=a[i][2];
			}
	return;
}
int main()
{
	int i,j,k;
	while(1)
	{
		ans=0;
		for(i=0;i<6;i++)
			for(j=0;j<3;j++)
				scanf("%d",&a[i][j]);
		dfs(1);
		if(ans!=0)
			printf("%d\n",ans);
		else
			printf("%s\n","none");
		scanf("%s",s);
		if(s[0]=='$')
			break;
	}
	return 0;
}