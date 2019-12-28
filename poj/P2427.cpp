#include<algorithm>
#include<iostream>
#include<math.h>
using namespace std;
int a[100005],x[1005],y[1005];
int b,g,h,i,j,k,n,m,sq,w,jx,jy,t;
int main()
{
	while(scanf("%d",&n)+1)
	{
		sq=(int)sqrt(1.0*n);
		if(n==sq*sq)
		{
			printf("No solution!\n");
			continue;
		}
		memset(a,0,sizeof(a));
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		g=a[h=i=1]=sq;
		while(a[i]!=2*a[1])
		{
			i++;
			h=(n-g*g)/h;
			a[i]=(sq+g)/h;
			g=a[i]*h-g;
		}
		m=i;
		y[1]=1;
		x[1]=a[m-1];
		b=m-1;
		if(m%2==0)
		{
			for(j=m+1;j<=2*m-2;j++)
				a[j]=a[j-m+1];
			x[1]=a[2*m-2];
			b=2*m-2;
		}
		for(k=b-1;k>0;k--)
			for(h=0,j=1;j<=1004;j++)
			{
				w=x[j]*a[k]+y[j]+h;
				h=w/10;
				y[j]=x[j];
				x[j]=w-h*10;
			}
		for(jx=1004;x[jx]==0;jx--);
		for(jy=1004;y[jy]==0;jy--);
		if(jx>1000||jy>1000)
		{
			printf("No solution!\n");
			continue;
		}
		for(i=jx;i>=1;i--)
			printf("%d",x[i]);
		printf(" ");
		for(i=jy;i>=1;i--)
			printf("%d",y[i]);
		printf("\n");
	}
	return 0;
}