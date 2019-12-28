#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a[100020];
int c[100020];
int s[100020];
int n,x,y,h,e;
int i,j,k;
int l,r,mid;
int nd;
int max(int x,int y)
{
	return x>y?x:y;
}
int cmp(const void *a,const void *b)
{
	return *(int*)b-*(int*)a;
}
int slove(int x)
{
	memcpy(c+1,a+1,4*x);
	qsort(c+1,x,4,cmp);
	int rep=h-s[x-1];
	for(i=1;rep<=0&&i<=x;i++)
		rep+=max(c[i],y);
	return x-i+1;
}
int check(int x)
{
	if(slove(x)>=nd)
		return 1;
	else
		return 0;
}
int main()
{
	scanf("%d %d %d %d %d",&n,&x,&y,&h,&e);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	l=0;
	r=n;
	nd=(e-1)/x+1;
	if(!check(n))
	{
		printf("Lose\n%d\n",x*slove(n));
	}
	else
	{
		while(l<r)
		{
			mid=(l+r)/2;
			if(check(mid))
				r=mid;
			else
				l=mid+1;
		}
		printf("Win\n%d\n",l);
	}
	return 0;
}
