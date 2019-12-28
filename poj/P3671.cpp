#include<stdio.h>
int c[30020];
int a[3],b[3];
int main()
{
int n,r,i;
scanf("%d",&n);
for(i=1;i<=n;i++)
{
scanf("%d",&c[i]);
a[c[i]]++;
}
r=a[1];
for(i=1;i<=n;i++)
{
b[c[i]]++;
r>(a[1]-b[1]+b[2])?r=(a[1]-b[1]+b[2]):0;
}
printf("%d",r);
return 0;
}