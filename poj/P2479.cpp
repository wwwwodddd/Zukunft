#include"stdio.h"
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
int sum,max,min,mi;
int a[100020];
int l[100020];
int r[100020];
int m,n;
int i,j,k;
int main()
{
scanf("%d",&k);
while(k--)
{
scanf("%d",&n);
l[0]=r[n+1]=max=-0x3fffffff;
for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
min=0;
for(i=1;i<=n;i++)
    {
	if(min<0)
		min=0;
	min+=a[i];
    l[i]=max(l[i-1],min);
    }
min=0;
for(i=n;i>0;i--)
    {
	if(min<0)
		min=0;
	min+=a[i];
    r[i]=max(r[i+1],min);
    }
for(i=1;i<n;i++)
	max=max(max,l[i]+r[i+1]);
printf("%d\n",max);
}
return 0;
}

