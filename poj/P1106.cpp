#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
int tx,ty,n,i,j,k,x[200], y[200],ans;
double r;
int dis()
{
	return (x[0]-tx)*(x[0]-tx)+(y[0]-ty)*(y[0]-ty)<=r*r;
}
int xm(int i,int j)
{
	return (tx-x[i])*(ty-y[j])-(tx-x[j])*(ty-y[i])>=0;
}
int main()
{
	while(scanf("%d%d%lf",&tx,&ty,&r),r>0)
	{
		scanf("%d",&n);
		j=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&x[0],&y[0]);
			if(dis())
			{
				j++;
				x[j]=x[0];
				y[j]=y[0];
			}
		}
		n=j;
		ans=0;
		for(i=1;i<=n;i++)
		{
			for(k=0,j=1;j<=n;j++)
				if(xm(i,j))
					k++;
			ans=max(ans,k);
		}
		printf("%d\n",ans);
	}
	return 0;
}