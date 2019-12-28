#include<stdio.h>
int a[1020];
int n,ans;
int check()
{
int f[1020]={},s[1020]={},g=0,h=1;
int i;
for(i=1;i<=n;i++)
	{
	if(f[a[i]]==0)
		{
		while(h!=a[i])
			if(f[h]!=1)
				s[g++]=h,f[h++]=1;
			else
				h++;
		f[h]=1;
		}
	else if(f[a[i]]==1)
		{
		if(s[g-1]==a[i])
			g--;
		else
			return 1;
		}
	}
return 0;
}
int main()
{
	while(scanf("%d",&n)&&n)
	{
		while(scanf("%d",&a[1])&&a[1])
		{
			for(int i=2;i<=n;i++)
				scanf("%d",&a[i]);	
			if(!check())
				printf("Yes\n");
			else
				printf("No\n");
		}
	printf("\n");
	}
	return 0;
}