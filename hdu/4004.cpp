#include<stdio.h>
#include<algorithm>
using namespace std;
int l,n,m;
int a[500020];
int ok(int x)
{
	int _=0,j;
	for(int i=0;i<m;i++)
	{
		j=_;
		while(j<n-1&&a[j+1]-a[_]<=x)
			j++;
		_=j;
	}
	return _==n-1;
}
int main()
{
	while(~scanf("%d %d %d",&l,&n,&m))
	{
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		a[n++]=0;
		a[n++]=l;
		sort(a,a+n);
		int L=0,R=l+1;
		while(L<R-1)
		{
			int M=L+R>>1;
			if(ok(M))
				R=M;
			else
				L=M;
		}
		printf("%d\n",R);
	}
	return 0;
}
