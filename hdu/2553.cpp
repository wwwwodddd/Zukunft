#include<stdio.h>
int a[30],b[30],c[30],n,z[30];
void dfs(int x)
{
	if(x==n)
		z[n]++;
	else
		for(int y=0;y<n;y++)
			if(!a[y]&&!b[x+y]&&!c[x-y+n])
			{
				a[y]=b[x+y]=c[x-y+n]=1;
				dfs(x+1);
				a[y]=b[x+y]=c[x-y+n]=0;
			}
}
int main()
{
	for(n=1;n<11;n++)
		dfs(0);
	while(scanf("%d",&n),n)
		printf("%d\n",z[n]);
	return 0;
}
