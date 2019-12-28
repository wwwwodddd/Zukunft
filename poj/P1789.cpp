#include<stdio.h>
char a[2001][7];
int d[2001];
int n;
int m(int x,int y)
{
	if(x==y)
		return 0;
	int r=0;
	for(int i=0;i<7;i++)
		if(a[x][i]!=a[y][i])
			r++;
	return r;
}
void prim()
{
	int i,j,l,x,ans=0;
	for(i=0;i<n;i++)
		d[i]=m(0,i);
	for(i=1;i<n;i++)
	{
		l=0x3fffffff;
		for(j=1;j<n;j++)
			if(d[j]>0&&d[j]<l)
				l=d[x=j];
		ans+=l;
		d[j]=0;
		for(j=1;j<n;j++)
			if(d[j]>0&&d[j]>m(x,j))
				d[j]=m(x,j);
	}
	printf("The highest possible quality is 1/%d.\n",ans);
}
int main()
{
	int i,j,k;
	int d;
	while(scanf("%d",&n)&&n)
	{
		for(i=0;i<n;i++)
			scanf("%s",a[i]);
		prim();
	}
	return 0;
}
