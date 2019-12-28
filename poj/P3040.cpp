#include<iostream>
using namespace std;
const int mi=0x3f3f3f3f;
struct N{int c,w;}a[30];
int v[30],i,j,n,c,z,ans;
int cmp(const void *a,const void *b)
{
	return ((N*)a)->w-((N*)b)->w;
}
int main()
{
	scanf("%d%d",&n,&c);
	for(i=0;i<n;i++)
		scanf("%d%d",&a[i].w,&a[i].c);
	qsort(a,n,8,cmp);
	while(1)
	{
		z=c;
		memset(v,0,sizeof(v));
		for(i=n-1;i>=0;i--)
			while(a[i].c-v[i]&&a[i].w<=z)
			{
				z-=a[i].w;
				v[i]++;
			}
		if(z)
			for(i=0;i<n;i++)
				if(a[i].c-v[i])
				{
					z-=a[i].w;
					v[i]++;
					break;
				}
		if(z>0)
			break;
		else
		{
			z=mi;
			for(i=0;i<n;i++)
				if(v[i])
					z=min(z,a[i].c/v[i]);
			ans+=z;
			for(i=0;i<n;i++)
				a[i].c-=z*v[i];
		}
	}
	printf("%d\n",ans);
	return 0;
} 
