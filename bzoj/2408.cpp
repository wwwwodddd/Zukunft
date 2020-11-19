#include<stdio.h>
#include<algorithm>
int a[10020],b[10020],n,m;
bool cmp(int x,int y)
{
	return a[x]<a[y];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	   scanf("%d",a+i),b[i]=i;
	std::stable_sort(b,b+n,cmp);
	for(int i=m=0;i<n;i++)
		printf("%d%c",a[m=b[m]],i<n-1?' ':'\n');
	return 0;
}
