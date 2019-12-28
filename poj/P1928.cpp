#include<iostream>
#include<math.h>
using namespace std;
int a[100][100];
int xx,yy;
int ttt;
int main()
{
	int t,m,n,k,i,j,sum;
	cin>>t;
	while(t--)
	{
		sum=xx=yy=ttt=0;
		scanf("%d %d %d",&m,&n,&k);
		for(i=1;i<=m;i++)
			for(j=0;j<n;j++)
				scanf("%d",&a[i][j]);
		while(1)
		{
			int x=xx,y=yy;
			for(i=1;i<=m;i++)
				for(j=0;j<n;j++)
					if(a[xx][yy]<a[i][j])
						xx=i,yy=j;
			if(x==0)
				y=yy;
			if(ttt+abs(xx-x)+abs(yy-y)+1+xx<=k)
			{
				ttt+=abs(xx-x)+abs(yy-y)+1;
				sum+=a[xx][yy];
				a[xx][yy]=0;
				x=xx;
				y=yy;
			}
			else
			{
				printf("%d\n",sum);
				break;
			}
		}
	}
	return 0;
}