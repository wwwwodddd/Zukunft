#include<iostream>
using namespace std;
int i,j,m,n,q,x,u,v;
int a[100];
int main()
{
	while(scanf("%d %d",&n,&q)&&n+q)
	{
		u=v=0;
		memset(a,0,sizeof(a));
		while(n--)
		{
			scanf("%d",&m);
			while(m--)
			{
				scanf("%d",&x);
				a[x]++;
			}
		}
		for(i=0;i<100;++i)
			if(a[i]>=q&&u<a[i])
				u=a[i],v=i;
		printf("%d\n",v);
	}
	return 0;
}
