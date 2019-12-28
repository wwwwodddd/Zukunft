#include<stdio.h>
int f[100020],n,x,l,r,h,j,m;
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		h=0;
		for(j=0;j<n;j++)
			{
			scanf("%d",&x);
			if(f[h]<x)
				f[++h]=x;
			else
				{
				for(l=0,r=h;l!=r;f[m]<x?l=m+1:r=m)
					m=(l+r)/2;
				f[l]=x;
				}
			}
		printf("%d\n",h);
	}
	return 0;
}
