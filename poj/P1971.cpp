#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int p[600000][2];
int o[1020][2];
int n,m,t,c,ans;
int cmp(const void *a,const void *b)
{
if(((int*)a)[0]==((int*)b)[0])
	return ((int*)a)[1]-((int*)b)[1];
else
	return ((int*)a)[0]-((int*)b)[0];
}
int main()
{
	int i,j,k;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		m=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
		scanf("%d %d",&o[i][0],&o[i][1]);
			for(j=0;j<i;j++)
			{
				p[m][0]=o[i][0]+o[j][0];
				p[m++][1]=o[i][1]+o[j][1];
			}
		}
		qsort(p,m,8,cmp);
		for(i=0;i<m;i++)
			if(p[i][0]==p[i+1][0]&&p[i][1]==p[i+1][1])
				c++;	
			else
			{
				ans+=c*(c-1)/2;
				c=1;
			}
		printf("%d\n",ans);
	}
	return 0;
}