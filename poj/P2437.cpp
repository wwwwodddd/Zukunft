#include<stdio.h>
#include<stdlib.h>
int a[10020][2],ans,n,l,i,p,x;
int cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
int main()
{
	scanf("%d%d",&n,&l);
	for(i=0;i<n;i++)
		scanf("%d %d",&a[i][0],&a[i][1]);
	qsort(a,n,8,cmp);
	for(i=0;p<n;)
	{
		if(i<a[p][0])
			i=a[p][0];
		x=(a[p][1]-i+l-1)/l;
		i+=x*l;
		ans+=x;
		while(i>=a[p][1]&&p<n)
			p++;
	}
	printf("%d\n", ans);
	return 0;
}
