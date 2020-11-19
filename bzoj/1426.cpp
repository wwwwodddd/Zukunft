#include<stdio.h>
double ans,sum,p;
int i,n;
int main()
{
	scanf("%d",&n);
	for(i=n;i>0;i--)
	{
		p=(double)i/n;
		ans+=1/p/p+sum/p;
		sum+=1/p;
	}
	printf("%.2lf",ans);
	return 0;
}