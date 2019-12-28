#include<stdio.h>
#include<string.h>
int s[120],n,w,x,v;
double z;
int main()
{
	while(scanf("%d %d",&n,&w),n+w)
	{
		v=0;
		memset(s,0,sizeof s);
		for(int i=0;i<n;i++)
			scanf("%d",&x),s[x/w]++;
		for(int i=0;i<110;i++)
			if(s[i])
			{
				n=i;
				if(s[i]>v)
					v=s[i];
			}
		z=0.01;
		for(int i=0;i<=n;i++)
			z+=(double)s[i]/v*(n-i)/n;
		printf("%.15f\n",z);
	}
	return 0;
}