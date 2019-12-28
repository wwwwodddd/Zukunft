#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[100020][6];
int i,j,n,v;
int cmp(const void *a,const void *b)
{
	for(int i=0;i<6;i++)
		if(((int*)a)[i]!=((int*)b)[i])
			return ((int*)a)[i]-((int*)b)[i];
	v=1;
	return 0;
}
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<6;j++)
				scanf("%d",&a[i][j]);
			sort(a[i],a[i]+6);
		}
		v=0;
		qsort(a,n,24,cmp);
		if(v)
			printf("Twin snowflakes found.\n");
		else
			printf("No two snowflakes are alike.\n");
	}
	return 0;
}
