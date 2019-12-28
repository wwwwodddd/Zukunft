#include<stdio.h>
#include<math.h>
#include<string.h>
int n,sq;
char a[50020],b[50];
int sqrt(int x)
{
return (int)sqrt((double)(x));
}
int fac(int f)
{
int i,j=0;
memset(b,0,sizeof(b));
for(i=2;i<=sqrt(f);i++)
	if(a[i])
		while(f%i==0)
		{
		b[j++]=i;
		f/=i;
		}
if(f!=1)
b[j++]=f;
return j;
}
int sm1(int d)
{
int sum=0;
while(d!=0)
	{
	sum+=d%10;
	d/=10;
	}
return sum;
}
int sm2(int e)
{
int sum=0,i,j;
j=fac(e);
for(i=0;i<j;i++)
	sum+=sm1(b[i]);
return sum;
}
int main()
{
int i,j,k;
memset(a,1,sizeof(a));
n=50000;
a[1]=0;
sq=sqrt(n);
for(i=2;i<sq;i++)
	if(a[i])
		for(j=i+i;j<n;j+=i)
			a[j]=0;
for(i=2;i<4937776;i++)
	if(sm1(i)==sm2(i)&&a[i]==0)
		printf("%d\n",i);
return 0;
}