#include<stdio.h>
#include<algorithm>
int n,m,a[1000020];
int main()
{
	for(;scanf("%d %d",&n,&m),n+m;)
	{
		if(m>n)
			m=n;
		for(int i=0;i<n;i++)
			scanf("%d",a+i),a[i]=-a[i];
		std::nth_element(a,a+m,a+n);
		std::sort(a,a+m);
		for(int i=0;i<m;i++)
			printf("%d%c",-a[i],i==m-1?'\n':' ');
	}
}
