#include<stdio.h>
#include<string.h>
int d[10020];
int a[105];
double b[105],sum;
int n,i,j;
void print(int x)
{
	if(x==0)
		return;
	print(x-a[d[x]]);
	printf("%d ",d[x]);
}
int main()
{
	while(scanf("%d",&n),n)
	{
	sum=0;
	for(i=1;i<=n;i++)
	{
		scanf("%lf",&b[i]);
		sum+=b[i];
	}
	for(i=1;i<=n;i++)
		a[i]=int(b[i]/sum*20000);
	memset(d,0,sizeof(d));
	d[0]=1;
	for(i=1;i<=n;i++)
		for(j=10000-a[i];j>=0;j--)
			if(d[j]&&!d[j+a[i]])
				d[j+a[i]]=i;
	for(i=10000;!d[i];i--);
	print(i);
	printf("\n");
	}
	return 0;
}

