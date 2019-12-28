#include<stdio.h>
int f[2020][2020];
int a[2020];
int n,i;
int max(int x,int y)
{
	return x>y?x:y;
}
int F(int x,int y)
{
	if(f[x][y])
		return f[x][y];
	if(x==y)
		return a[x]*n;
	return f[x][y]=max(F(x+1,y)+a[x]*(n-y+x),F(x,y-1)+a[y]*(n-y+x));
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	printf("%d",F(1,n));
	return 0;
}