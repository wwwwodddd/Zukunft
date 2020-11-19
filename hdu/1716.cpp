/*
  Name: 
  Copyright: 
  Author: 
  Date: 30-12-11 19:16
  Description: 
*/
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int a[4],v[4];
int ans[1000],aa;
void dfs(int x,int y)
{
	int i;
	if(x==4)
	{
		ans[aa++]=y;
		return;
	}
	for(i=0;i<4;i++)
		if(!v[i])
		{
			v[i]=1;
			dfs(x+1,y*10+a[i]);
			v[i]=0;
		}
	return;
}
int main()
{
	freopen("c.out","w",stdout);
	int i,cnt=0;;
	while(1)
	{
		for(i=0;i<4;i++)
			scanf("%d",&a[i]);
		if(a[0]+a[1]+a[2]+a[3]==0)
			break;
		if(cnt)
			puts("\n");
		cnt++;
		aa=0;
		sort(a,a+4);
		dfs(0,0);
		sort(ans,ans+aa);
		aa=unique(ans,ans+aa)-ans;
		for(i=0;ans[i]<1000;i++);
		for(;i<aa;i++)
		{
			printf("%d",ans[i]);
			if(ans[i]/1000!=ans[i+1]/1000)
			{
				if(i!=aa-1)
				puts("");
			}
			else
				putchar(' ');	
		}
	}
	return 0;
}
