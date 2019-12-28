#include<stdio.h>
#include<stdio.h>
int a[1000020],q[1000020],p[1000020];
int n,m,b=1,f;
int i,j,k;
int main()
{
scanf("%d %d",&n,&m);
for(i=0;i<n;i++)
	scanf("%d",&a[i]);
q[0]=-2147483647;
for(i=0;i<n;i++)
	{
	if(a[i]>q[f])
		q[f]=a[i],p[f++]=i;
	if(i-p[b]>=m)
		b++;
	printf("%d ",q[b]);
	}
return 0;
}