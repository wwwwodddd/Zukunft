#include<stdio.h>
#include<string.h>
int a[102][3];
int n,m,d[102];
int BF()
{
	int i,j,u;
	memset(d,0,sizeof(d));
	for(i=0;i<=n;i++)
	{
		u=0;
		for(j=0;j<m;j++)
			if(d[a[j][0]]+a[j][2]<d[a[j][1]])
			{
				d[a[j][1]]=d[a[j][0]]+a[j][2];
				u=1;
			}
		if(!u)
			return 1;
	}
	return 0;
}
int i,x,y,z;
char s[4];
int main()
{
	while(scanf("%d",&n)&&n)
	{
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%d %d %s %d",&x,&y,s,&z);
			if(s[0]=='g')
			{
				a[i][0]=x+y;
				a[i][1]=x-1;
				a[i][2]=-1-z;
			}
			else if(s[0] == 'l')
			{
				a[i][0]=x-1;
				a[i][1]=x+y;
				a[i][2]=z-1;
			}
		}
		if(BF())
			printf("lamentable kingdom\n");
		else
			printf("successful conspiracy\n");
	}
	return 0;
}
