#include<stdio.h>
#include<string.h>
int a[200005][3];
int d[1005];
int n,m;
int tot;
void add(int x,int y,int z)
{
	tot++;
	a[tot][0]=x;
	a[tot][1]=y;
	a[tot][2]=z;
	return;
}
int BF()
{
	int i,j,u;
	for(i=1;i<=n;i++)
	{
		u=0;
		for(j=1;j<=tot;j++)
			if(d[a[j][1]]>d[a[j][0]]+a[j][2])
			{
				d[a[j][1]]=d[a[j][0]]+a[j][2];
				u=1;
			}
		if(u==0)
			return 1;
	}
	return 0;
}
int main()
{
	int i,x,y,z;
	char c;
	while(scanf("%d%d",&n,&m)+1)
	{
		memset(d,0,sizeof(d));
		tot=0;
		for(i=0;i<m;i++)
		{
			scanf("%s%d%d",&c,&x,&y);
			if(c=='P')
			{
				scanf("%d",&z);
				add(x,y,-z);
				add(y,x,z);
			}
			else if(c=='V')
				add(x,y,-1);
		}
		if(BF())
			printf("Reliable\n");
		else
			printf("Unreliable\n");
	}
	return 0;
}