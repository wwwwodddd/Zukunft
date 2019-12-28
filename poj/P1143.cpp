#include<stdio.h>
#include<string.h>
int sg[1050000];
int x,n,z,a,k;
int f(int x,int y)
{
	int a[32];
	for(int i=y;i<21;i+=y)
		x&=~(1<<(i-2));
	for(int i=2;i+y<21;i++)
		if((x&(1<<(i-2)))==0)
			x&=~(1<<(i+y-2));
	return x;
}
int SG(int x)
{
	if(sg[x]!=-1)
		return sg[x];
	if(x==0)
		return sg[x]=0;
	int u[50],p;
	memset(u,0,sizeof(u));
	for(int i=2;i<21;i++)
		if((x&(1<<(i-2)))>0)
			u[SG(f(x,i))]=1;
	for(p=0;u[p];p++);
		return sg[x]=p;
}
int main()
{
	memset(sg,-1,sizeof(sg));
	while(scanf("%d",&n)&&n)
	{
		printf("Test Case #%d\n",++k);
		z=a=0;
		while(n--)
			scanf("%d",&x),z|=1<<(x-2);
		for(int i=2;i<21;i++)
			if((z&(1<<(i-2)))>0&&SG(f(z,i))==0)
			{
				if(a==0)
					printf("The winning moves are:"),a=1;
				printf(" %d",i);
			}
		if(a==0)
			printf("There's no winning move.");
		printf("\n\n");
	}
	return 0;
}