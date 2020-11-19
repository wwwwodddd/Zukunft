#include<stdio.h>
int n,t,a[10020],s,x,d;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d %d",&x,&n);
		printf("%d ",x);
		for(int i=s=0;i<n;i++)
			scanf("%d",a+i),s+=a[i];
		for(int i=d=0,j;i<n;i++)
		{
			d+=a[i];
			if(s%d)
				continue;
			x=0;
			for(j=i+1;j<n;j++)
			{
				if(x>d)
					break;
				else if(x==d)
					x=a[j];
				else
					x+=a[j];
			}
			if(j==n&&x==d)
				break;
		}
		printf("%d\n",d);
	}
	return 0;
}
