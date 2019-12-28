#include<stdio.h>
int i,s,p,ans;
int main()
{
	while(scanf("%d %d",&s,&p)+1)
	{
		i=(5*p-1)/(s+p);
		ans=i*2*s-(5-i)*2*p;
		if (i>=2)
			ans+=2*s;
		else
			ans+=i*s-(2-i)*p;
		if(ans>0)
			printf("%d\n",ans);
		else
			printf("Deficit\n");
	}
	return 0;
}
