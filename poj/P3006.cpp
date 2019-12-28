#include<stdio.h>
#include<math.h>
#include<string.h>
int i,j;
int b,d,n;
int a[1000000];
int main()
{
memset(a,1,sizeof(a));
	a[1]=0;
for(i=2;i<1000;i++)
    if(a[i])
	    for(j=i+i;j<1000000;j+=i)
	    	a[j]=0;
while(scanf("%d %d %d",&b,&d,&n)&&b!=0&&d!=0&&n!=0)
{
while(n)
	{
	if(a[b])
		n--;
	b+=d;
	}
printf("%d\n",b-d);
}
return 0;
}

