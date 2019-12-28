#include<stdio.h>
int a[1000020],k=1000000000,n,i;
int main()
{
scanf("%d",&n);
a[1]=1;
a[2]=2;
for(i=3;i<=n;i++)
{
if(i&1)
a[i]=a[i-1];
else
a[i]=(a[i-1]+a[i>>1])%k;
}
printf("%d",a[n]);
return 0;
}
