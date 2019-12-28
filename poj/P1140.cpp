#include<stdio.h>
#include<string.h>
int v[1020];
int r[1020];
int m,n,i,k;
int main()
{
	while(scanf("%d %d",&m,&n)&&n)
	{
		k=1;
		memset(v,0,sizeof(v));
		while(!v[m]&&m)
		{
			v[m]=k;
			m*=10;
			r[k++]=m/n;
			m%=n;
		}
		printf(".");
		for(i=1;i<k;i++)
		{
			if(i%50==0)
				printf("\n");
			printf("%d",r[i]);
		}
		printf("\n");
		if(m==0)
			printf("%s","This expansion terminates.\n");
		else
			printf("The last %d digits repeat forever.\n",k-v[m]);
	}
	return 0;
}