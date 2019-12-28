#include<stdio.h>
int main()
{
	int n,k;
	int s,t,r,i,j,m;
	scanf("%d %d",&n,&k);
	while(k--)
	{
		m=0;
		scanf("%d %d %d",&s,&t,&r);
		j=n%(s*t);
		if(j==0)
		{
			i=n/(s*t);
			printf("%d\n",i*(t+r)-r);
		}
		else
		{
			i=n/(s*t);
			while((++m)*s<j);
			printf("%d\n",i*(t+r)+m);
		}
	}
	return 0;
}