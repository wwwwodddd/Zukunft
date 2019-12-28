#include<stdio.h>
#include<string.h>
char a[5000],b[5000];
int m,v,u;
void dfs(int z,int &p)
{
	int k=-1,p1=0,p2=0;
	a[0]=0;
	scanf("%[ (\n]",b);
	scanf("%[-0-9 \n]",a);
	sscanf(a,"%d",&k);
	if(a[0])
	{
		p=1;
		dfs(z+k,p1);
		dfs(z+k,p2);
		if(z+k==m&&p1==0&&p2==0)
			v=1;
	}
	scanf("%[ )\n]",b);
}
int main()
{
	while(scanf("%d",&m)+1)
	{
		v=u=0;
		dfs(0,u);
		puts(v?"yes":"no");
	}
	return 0;
}