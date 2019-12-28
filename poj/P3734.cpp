#include<stdio.h>
int a[10020];
int f(int x)
{
x%=10006;
long long z=1,y=1,c=2;
while(x)
{
if(x&1)
{
z=z*c%10007;
y=y*(c*c%10007)%10007;
}
c=c*c%10007;
x>>=1;
}
return (z+y)%10007;
}
int main()
{
int i,j,ans,n;
scanf("%d",&n);
while(n--)
{
	scanf("%d",&ans);
	printf("%d\n",f(ans-1));
}
return 0;
}