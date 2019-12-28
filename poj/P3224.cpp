#include<stdio.h>
int w,u,v,n,x,i,j;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		w=0;
		for(j=0;j<n;j++)
		{
			scanf("%d", &x);
			if(x==3)
				w++;
		}
		if(u<w)
			u=w,v=i;
	}
	printf("%d",v);
	return 0;
}