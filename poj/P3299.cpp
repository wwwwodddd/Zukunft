#include<stdio.h>
#include<string.h>
int c[10];
int main()
{
int x,y,n,a,b;
scanf("%d",&n);
while(n--)
{
a=b=0;
memset(c,0,sizeof(c));
scanf("%d %d",&x,&y);
c[x%10]++;
c[x/10%10]++;
c[x/100%10]++;
c[x/1000%10]++;
if(c[y%10])
	b++;
if(c[y/10%10])
	b++;
if(c[y/100%10])
	b++;
if(c[y/1000%10])
	b++;
if(x%10==y%10)
	a++;
if(x/10%10==y/10%10)
	a++;
if(x/100%10==y/100%10)
	a++;
if(x/1000%10==y/1000%10)
	a++;
printf("%dA%dB\n",a,b-a);
}
return 0;
}