#include<stdio.h>
#include<stdlib.h>
int q[12000000],i,f;
int cmp(const void *a,const void *b)
{
return *(int *)a-*(int *)b;
}
int main()
{
q[f++]=1;
for(i=0;f!=3200;i++)
	if(q[i]*2+1<10000000)
		q[f++]=q[i]*2+1;
for(i=0;f!=11000000;i++)
	if(q[i]*3+1<10000000)
		q[f++]=q[i]*3+1;
qsort(q,f,4,cmp);
for(i=0;i<f;i++)
	printf("%d ",q[i]);
printf("\n\n\n%d",q[253]);
return 0;
}