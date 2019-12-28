#include<iostream>
using namespace std;
char ch[20][20];
bool v[20];
int n,m,t,ans;
int l[20],d[20][20];
int check(int x,int y)
{
	int i,j,k;
	for(i=0;i<l[x];i++)
		if(ch[x][i]==ch[y][0])
		{
			for(k=i,j=0;k<l[x]&&j<l[y];j++,k++)
				if(ch[x][k]!=ch[y][j])
					break;
			if(k==l[x])
				return j;
		}
	return 0;
}
void dfs(int x,int y,int z)
{
	if(y==n)
	{
		ans=min(z,ans);
		return;
	}
	for(int i=0;i<n;i++)
		if(!v[i])
		{
			v[i]=1;
			dfs(i,y+1,z+l[i]-d[x][i]);
			v[i]=0;
		}
}
int main()
{
	int i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%s",ch[i]);
			l[i]=strlen(ch[i]);
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				d[i][j]=check(i,j);
		ans=0x3f3f3f3f;
		for(i=0;i<n;i++)
		{
			v[i]=1;
			dfs(i,1,l[i]);
			v[i]=0;
		}
		printf("%d\n",ans);
	}
	return 0;
}
