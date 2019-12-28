#include<stdio.h>
#include<string.h>
int a[100010];
int t[100010];
int b[120];
unsigned int c[120];
int v[120];
int main()
{
int m,n,max=0;
int i,j,k;
scanf("%d %d",&n,&m);
memset(a,0,sizeof(a));
for(i=0;i<n;i++)
	scanf("%d %d %d",&c[i],&b[i],&v[i]);
for(i=0;i<n;i++)
	{
	memset(t,0,sizeof(t));
	for(j=0;j<=m;j++)
		if(a[j+b[i]]<a[j]+v[i]&&t[j]<c[i]&&j+b[i]<=m)
		{
		a[j+b[i]]=a[j]+v[i];
		t[j+b[i]]=t[j]+1;
		}
	}
for(i=m;i>=0;i--)
{
if(a[i]>max)
	max=a[i];
}
printf("%d\n",max);
return 0;
}
