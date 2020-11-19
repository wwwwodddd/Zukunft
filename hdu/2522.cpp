#include<stdio.h>
#include<string.h>
int t,n,v[100020],z;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		memset(v,0,sizeof v);
		scanf("%d",&n);
		if(n<0)
			printf("-"),n=-n;
		if(n==1)
		{
			puts("1");
			continue;
		}
		printf("0.");
		for(z=1;z&&!v[z];z=z*10%n)
		{
			v[z]=1;
			printf("%d",z*10/n);
		}
		puts("");
	}
	return 0;
}
