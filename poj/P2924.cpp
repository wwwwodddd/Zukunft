#include<stdio.h>
int main()
{
long long n,a,b,i=1;
scanf("%I64d",&n);
while(n--)
{
scanf("%I64d %I64d",&a,&b);
printf("Scenario #%d:\n",i++);
printf("%I64d\n\n",(b-a+1)*(b+a)/2);
}
return 0;
}