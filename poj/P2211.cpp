#include<stdio.h>
int a[20],n,k,z,d,u,t;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d %d",&n,&k);
		z=1;
		for(int i=0;i<k;i++)
			scanf("%d",a+i);
		for(int i=0;i<k;i++)
		{
			d=a[i]-1;
			for(int j=i+1;j<k;j++)
				d*=n-j;
			z+=d;
			for(int j=i+1;j<k;j++)
				if(a[j]>a[i])
					a[j]--;
		}
		printf("Variace cislo %d ma poradove cislo %d.\n",++u,z);
	}
}
