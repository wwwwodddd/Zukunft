#include<iostream>
#define t a[i]-a[j]-a[k]
#define mid (l+r)/2
using namespace std;
int a[1010];
int cmp(const void *a , const void *b)
{
return -(*(int*)a-*(int*)b);
}
bool search(int l,int r,int x)
{
	while(l<=r)
		if(a[mid]==x)
			return 1;
		else if(a[mid]>x)
			l=mid+1;
		else if(a[mid]<x)
			r=mid-1;
	return 0;
}
int main()
{
	int i,j,k,n;
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		qsort(a,n,4,cmp);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(a[j]!=a[i])
					for(k=n-1;k>j;k--)
						if(a[k]!=a[i])
							if(t<a[j]&&t>a[k]&&search(j,k,t))
								goto o;
		printf("no solution\n");
		continue;
		o:
		printf("%d\n",a[i]);
	}
	return 0;
}