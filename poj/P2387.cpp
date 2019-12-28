#include<stdio.h>
int e[2020][3],d[1020];
int main()
{
	int i,j,k,n,t,f;
	scanf("%d %d",&t,&n);
	for(i=0;i<t;i++)
		scanf("%d %d %d",&e[i][0],&e[i][1],&e[i][2]);
	f=1;
	for(i=2;i<=n;i++)
		d[i]=0x3fffffff;
	while(f)
	{
	f=0;
	for(i=0;i<t;i++)
		{
			if(d[e[i][1]]>d[e[i][0]]+e[i][2])
			{
				d[e[i][1]]=d[e[i][0]]+e[i][2];
				f=1;
			}
			if(d[e[i][0]]>d[e[i][1]]+e[i][2])
			{
				d[e[i][0]]=d[e[i][1]]+e[i][2];
				f=1;
			}	
		}
	}
	printf("%d\n",d[n]);
	return 0;
}