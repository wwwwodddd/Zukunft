#include<stdio.h>
int f[40020];
int i,n,l,r;
int x,y,t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		x=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&y);
			if(y>f[x])
				f[++x]=y;
			else
			{
				l=1;
				r=x;
				while(l!=r)
					if(f[(l+r)/2]>y)
						r=(l+r)/2;
					else
						l=(l+r)/2+1;
				f[l]=y;
			}
		}
		printf("%d\n",x);
	}
	return 0;
}