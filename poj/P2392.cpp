#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a[50010];
int t[50010];
int c[420][3];
int cmp(const void *a,const void *b)
{
return ((int *)a)[1]-((int *)b)[1];
}
int main()
{
int m,n;
int i,j,k;
m=42000;
scanf("%d",&n);
memset(a,0,sizeof(a));
a[0]=1;
for(i=0;i<n;i++)
	scanf("%d %d %d",&c[i][0],&c[i][1],&c[i][2]);
qsort(c,n,sizeof(c[0]),cmp);
for(i=0;i<n;i++)
	{
	memset(t,0,sizeof(t));
	for(j=0;j<=m;j++)
		if(a[j]&&t[j]<c[i][2]&&a[j+c[i][0]]==0&&j+c[i][0]<=c[i][1])
		{
		a[j+c[i][0]]=1;
		t[j+c[i][0]]=t[j]+1;
		}
	}
for(i=m;i>=0;i--)
{
if(a[i]==1)
	{
	printf("%d\n",i);
	break;
	}
}
return 0;
}
