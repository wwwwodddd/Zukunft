#include<stdio.h>
int a,min,max,sum,ans;
int main()
{
while(scanf("%d",&a))
{
sum=min=max=a;
for(int i=1;i<6;i++)
{
scanf("%d",&a);
max<a?max=a:0;
min>a?min=a:0;
sum+=a;
}
if(sum==0&&min==0&&max==0)
	break;
ans=(sum-min-max);
if(ans%4==0)
	printf("%d\n",ans/4);
else if(ans%4==1)
	printf("%d.25\n",ans/4);
else if(ans%4==2)
	printf("%d.5\n",ans/4);
else if(ans%4==3)
	printf("%d.75\n",ans/4);
}
return 0;
}