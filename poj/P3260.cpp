#include<stdio.h>
#include<string.h>
int a[28810];
int f[28810];
int t[28810];
int b[120];
int c[120];
int main()
{
int m,n,mm,max;
int i,j,k;
m=28800;
while(scanf("%d %d",&n,&mm)!=EOF)
{
memset(a,0x3f,sizeof(a));
memset(f,0x3f,sizeof(f));
a[0]=f[0]=0;
for(i=0;i<n;i++)
	scanf("%d",&b[i]);
for(i=0;i<n;i++)
	scanf("%d",&c[i]);
for(i=0;i<n;i++)
	{
	memset(t,0,sizeof(t));
	for(j=0;j<=m;j++)
		if(a[j]+1<a[j+b[i]]&&t[j]<c[i]&&j+b[i]<=m)
		{
		a[j+b[i]]=a[j]+1;
		t[j+b[i]]=t[j]+1;
		}
	}
for(i=0;i<n;i++)
	{
	for(j=0;j<=m;j++)
		if(f[j]+1<f[j+b[i]]&&j+b[i]<=m)
		f[j+b[i]]=f[j]+1;
	}
max=0x3f3f3f3f;
for(i=14400;i>=0;i--)
{
if(max>f[i]+a[mm+i])
	{
	max=f[i]+a[mm+i];
	}
}
printf("%d\n",max==0x3f3f3f3f?-1:max);
}
return 0;
}
