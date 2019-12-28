#include<stdio.h>
#include<stdlib.h>
int a[50020][3];
int cmp1(const void *b,const void *a)
{
return *(int*)a-*(int*)b;
}
int cmp2(const void *b,const void *a)
{
return ((int*)a)[1]-((int*)b)[1];
}
int main()
{
int n,m;
int i,j;
while(scanf("%d %d",&n,&m)!=EOF)
{
for(i=0;i<n;i++)
	{
	scanf("%d %d",&a[i][0],&a[i][1]);
	a[i][2]=i+1;
	}
qsort(a,n,12,cmp1);
qsort(a,m,12,cmp2);
printf("%d",a[0][2]);
}
return 0;
}