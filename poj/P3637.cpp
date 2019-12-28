#include<stdio.h>
#include<stdlib.h>
int a[20020];
int n,i,m,sum;
int cmp(const void *b,const void *a)
{
return *((int *)a)-*((int *)b);
}
int main()
{
int m;
scanf("%d",&m);
while(m--)
{
sum=0;
scanf("%d",&n);
for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
qsort(a+1,n,4,cmp);
for(i=3;i<=n;i+=3)
	sum+=a[i];
printf("%d\n",sum);
}
return 0;
}