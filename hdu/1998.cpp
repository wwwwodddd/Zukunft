#include<stdio.h>
int t,n,x,y,a[60][60];
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&n);
		x=0,y=n/2;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				a[i][j]=0;
		for(int i=1;i<=n*n;i++)
		{
			a[x][y]=i;
			x=(x+n-1)%n,y=(y+1)%n;
			if(a[x][y])
				x=(x+2)%n,y=(y+n-1)%n;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				printf("%4d",a[i][j]);
			puts("");
		}
	}
}
