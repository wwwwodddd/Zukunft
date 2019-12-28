#include<stdio.h>
int a[40],c,n,x,y,z,t;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		c=x=y=z=0;
		scanf("%d",&n);
		for(;n;n>>=1)
			a[c++]=n&1;
		for(;x<c&&!a[x];x++)
			;
		for(y=x;y<c&&a[y];y++)
			a[y]=0;
		if(y==c)
			for(int i=2;i<c;i+=2)
				a[i]=1;
		else
		{
			a[y]=1;
			for(int i=1;i<y-x;i++)
				a[i*2]=1;
		}
		for(int i=0;i<c;i++)
			z|=a[i]<<i;
		printf("%d\n",z);
	}
	return 0;
}
