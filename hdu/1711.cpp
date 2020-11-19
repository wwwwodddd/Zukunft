#include<stdio.h>
int a[1000020];
int b[10020];
int p[100020];
int n,m,t,i,j;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d %d",&n,&m);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		for(i=1;i<=m;i++)
			scanf("%d",b+i);
		for(i=2,j=0;i<=m;i++)
		{
			while(j&&b[i]!=b[j+1])
				j=p[j];
			if(b[i]==b[j+1])
				j++;
			p[i]=j;
		}
		for(i=1,j=0;i<=n;i++)
		{
			while(j&&a[i]!=b[j+1])
				j=p[j];
			if(a[i]==b[j+1])
				j++;
			if(j==m)
				break;
		}
		if(i>n)
			puts("-1");
		else
			printf("%d\n",i-m+1);
	}
}
