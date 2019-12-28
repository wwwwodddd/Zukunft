#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int min(int a,int b)
{
return ((a)<(b)?(a):(b));
}
int cmp(const void *a,const void *b)
{
if(*(int *)a-*(int *)b==0)
	return ((int *)b)[1]-((int *)a)[1];
return *(int *)a-*(int *)b;
}
int l[25020][2];
int f[1000020];
int main()
{
int i,j;
int m,n;
scanf("%d %d",&m,&n);
for(i=1;i<=m;i++)
	scanf("%d %d",&l[i][0],&l[i][1]);
qsort(l,m,8,cmp);
for(i=1;i<=n;i++)
	f[i]=0x3fffffff;
for(i=1;i<=m;i++)
    {
    for(j=l[i][1];j>=l[i][0];j--)
		{
		if(f[j]>f[l[i][0]-1]+1)
			f[j]=f[l[i][0]-1]+1;
		else
			break;
		}
	}
printf("%d",f[n]==0x3fffffff?-1:f[n]);
return 0;
}