#include<stdio.h>
#include<stdlib.h>
struct N
{
	int r,h,w,f,s;
}a[30020];
int cmp(const void *a,const void *b)
{
	return ((N *)a)->w-((N *)b)->w;
}
N *z[1000020];
int csc,i,j,n,q,x;
int main()
{
	scanf("%d",&csc);
	while(csc--)
	{
		scanf("%d%d",&n,&q);
		for(i=0;i<n;i++)
			scanf("%d%d%d",&a[i].r,&a[i].w,&a[i].h),a[i].s=0,a[i].f=0;
		qsort(a,n,sizeof(N),cmp);
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
				if(a[j].h>=a[i].h)
				{
					a[i].f=a[j].r;
					a[j].s+=a[i].s+1;
					break;
				}
		for(i=0;i<n;i++)
			z[a[i].r]=&a[i];
		for(i=0;i<q;i++)
		{
			scanf("%d",&x);
			printf("%d %d\n",z[x]->f,z[x]->s);
		}
	}
	return 0;
}