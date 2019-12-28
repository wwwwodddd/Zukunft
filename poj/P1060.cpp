#include<stdio.h>
#include<string.h>
int a[2010],b[2010],c[2010],d[2010],t;
void multipy()
{
	for(int i=1;i<=a[0];i++)
		for(int j=1;j<=b[0];j++)
			d[i+j-1]+=a[i]*b[j];
	for(int i=1;i<2005;i++)
		d[i]&=1;
	d[0]=2000;
	while(!d[d[0]]&&d[0])
		d[0]--;
	return;
}
void mod()
{
	for(int i=d[0];i>=c[0];i--)
		if(d[i]==1)
			for(int j=0;j<c[0];j++)
				d[i-j]^=c[c[0]-j];
	return;
}
void scan(int *a)
{
	scanf("%d",&a[0]);
	for(int i=a[0];i>0;i--)
		scanf("%d",&a[i]);
	return;
}
void print(int *a)
{
	a[0]=2005;
	while(!a[a[0]]&&a[0])
		a[0]--;
	printf("%d ",a[0]);
	for(int i=a[0];i>1;i--)
		printf("%d ",a[i]);
	printf("%d\n",a[1]);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		scan(a);
		scan(b);
		scan(c);
		multipy();
		mod();
		print(d);
	}
	return 0;
}