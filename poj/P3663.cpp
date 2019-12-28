#include<stdio.h>
#include<stdlib.h>
int a[20020];
int n,s,ans,x,b,f,q;
int cmp(const void *a, const void *b)
{
return *(int *)a-*(int *)b;
}
int main()
{
int i,j;
scanf("%d %d",&n,&s);
b=0;
f=n;
for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
qsort(a+1,n,4,cmp);
while(b<n)
	{
	b++;
	if(a[b]>=s)break;
	for(;a[b]+a[f]>s&&f>=0;f--);
	//printf("%d ",f+(f>=b?-1:0));
	if(f<b)break;
	ans+=f-b;
	}
printf("%d",ans);
return 0;
}