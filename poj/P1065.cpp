#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a[5020][2];
int b[5020];
int n,i,j,k,l,r,mid,t;
int cmp(const void *a,const void *b)
{
	if(((int*)a)[0]==((int*)b)[0])
		return ((int*)a)[1]-((int*)b)[1];
	return ((int*)a)[0]-((int*)b)[0];
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		k=1;
		memset(b,0,sizeof(b));
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d %d",&a[i][0],&a[i][1]);
		qsort(a,n,8,cmp);
		for(i=0;i<n;i++)
		{
			if(b[k]>a[i][1])
				b[++k]=a[i][1];
			else
			{
				l=1;
				r=k;
				while(l!=r)
				{
					mid=(l+r)/2;
					if(b[mid]>a[i][1])
						l=mid+1;
					else
						r=mid;
				}
				b[l]=a[i][1];
			}
		}
		printf("%d\n",k);
	}
	return 0;
}