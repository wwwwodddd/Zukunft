#include<stdio.h>
#include<string.h>
int t[100020];
int n,m,i,sum,x,j;
int main()
{
	while(scanf("%d %d",&n,&m)&&n+m)
	{
		memset(t,0,sizeof(t));
		sum=0;
		for(i=1;i<=m;i++)
		{
			scanf("%d",&x);
			sum+=x;
			sum%=n;
			if(sum==0)
			{
				for(j=1;j<=i;j++)
					printf("%d ",j);
				printf("\n");
				break;
			}
			if(!t[sum])
				t[sum]=i;
			else
			{
				for(j=t[sum]+1;j<=i;j++)
					printf("%d ",j);
				printf("\n");
				break;
			}
		}
		for(i++;i<=m;i++)
			scanf("%d",&x);
	}
	return 0;
}