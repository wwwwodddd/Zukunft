#include<stdio.h>
int main()
{
int n,i,x;
scanf("%d",&x);
while(scanf("%d",&n)!=EOF)
printf("%d %d\n",(n+1)-(n&(-n)),(n-1)+(n&(-n)));
return 0;
}