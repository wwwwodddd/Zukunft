#include<stdio.h>
int a[40]={1,0,3},b[40]={0,1},i,n;
int main()
{
for(i=2;i<32;i++)
{
	a[i]=2*b[i-1]+a[i-2];
	b[i]=b[i-2]+a[i-1];
}
while(scanf("%d",&n)&&n!=-1&&printf("%d\n",a[n]));
return 0;
}