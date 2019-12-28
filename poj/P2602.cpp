#include<stdio.h>
int n,x,y;
char r[3000000];
int main()
{
scanf("%d",&n);
int i;
for(i=1;i<=n;i++)
	{
	scanf("%d %d",&x,&y);
	r[i]=x+y;
	}
for(i=n;i>=1;i--)
	{
	if(r[i]>9)
		{
		r[i]-=10;
		r[i-1]++;
		}
	r[i]+='0';
	}
if(r[0])
	printf("%d",r[0]);
printf("%s",r+1);
return 0;
}