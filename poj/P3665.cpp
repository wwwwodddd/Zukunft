#include<stdio.h>
int a[10020];
int main()
{
int n,t,mp,mx,b,c;
int i,j,k;
scanf("%d %d",&n,&t);
for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
for(j=1;j<=t;j++)
	{
	mx=0;
	for(i=1;i<=n;i++)
		if(a[i]>mx)
			mp=i,mx=a[i];
	printf("%d\n",mp);
	b=mx/(n-1);
	c=mx%(n-1);
	for(i=1;i<=n;i++)
		a[i]+=b;
	a[mp]=0;
	for(i=1;i<=c;i++)
		a[i]++;
	if(a[mp]==1)
		a[mp]=0,a[c+1]++;
	}
return 0;
}