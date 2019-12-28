#include<stdio.h>
int n,x,y;
int main()
{
scanf("%d",&n);
while(n--)
{
scanf("%d %d",&x,&y);
if(x==y)
printf("%d\n",x/2*4+(x&1));
else if(x==y+2)
printf("%d\n",x/2*4-2+(x&1));
else 
printf("No Number\n");
}
return 0;
}