/*
  Name: 
  Copyright: 
  Author: 
  Date: 29-12-11 22:13
  Description: 
*/
#include<stdio.h>
int csc;
int n,st,ed,mx;
int ans,ast,aed;
int i,j,k,x;
int main()
{
	scanf("%d",&csc);
	while(csc--)
	{
		printf("Case %d:\n",++k);
		scanf("%d",&n);
		ast=st=1;
		aed=ed=1;
		mx=0;
		ans=0xcccccccc;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			mx+=x;
			ed=i;
			if(mx>ans)
			{
				ans=mx;
				ast=st;
				aed=ed;	
			}
			if(mx<0)
			{
				mx=0;
				st=i+1;
				ed=i+1;
			}
		}
		printf("%d %d %d",ans,ast,aed);
		if(csc)
			printf("\n\n");
		else
			printf("\n");
	}
	return 0;
}
// 1A
