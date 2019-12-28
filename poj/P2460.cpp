#include<iostream>
using namespace std;
int a[200000][2];
int n,i,j,x,y,u,v;
int main()
{
	while(scanf("%d",&n)&&n)
	{
		u=v=0;
		for(i=0;i<n;i++)
			scanf("%d %d",&a[i][0],&a[i][1]);
		x=a[n/2][0];
		y=a[n/2][1];
		for(i=0;i<n;i++)
			if(a[i][0]>x&&a[i][1]>y || a[i][0]<x&&a[i][1]<y)
				u++;
			else if(a[i][0]>x&&a[i][1]<y || a[i][0]<x&&a[i][1]>y)
				v++;
		printf("%d %d\n",u,v);
	}
	return 0;
}