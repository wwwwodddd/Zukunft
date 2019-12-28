#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
struct N{char c[16];int t[7],s,n,a;}d[24];
int n;
int c,i,j,r;
double e;
N *t;
int cmp(const void *_a,const void *_b)
{
	N *a=(N*)_a,*b=(N*)_b;
	if(a->n!=b->n)
		return b->n-a->n;
	if(a->s!=b->s)
		return a->s-b->s;
	if(a->a!=b->a)
		return a->a-b->a;
	return strcmp(a->c,b->c);
}
int main()
{
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;i++)
		{
			t=&d[i];
			scanf("%s",t->c);
			t->s=t->n=t->a=0;
			e=1;
			for(j=0;j<7;j++)
			{
				scanf("%d",&t->t[j]);
				if(!t->t[j])
					continue;
				t->s+=t->t[j];
				t->n++;
				e*=t->t[j];
			}
			if(t->n)
				t->a=(int)(pow(e,(double)1/t->n)+0.5);
		}
		qsort(d,n,sizeof(d[0]),cmp);
		printf("CONTEST %d\n",++c);
		for(r=i=0;i<n;i++)
		{
			if(i&&(d[i].n!=d[i-1].n||d[i].s!=d[i-1].s||d[i].a!=d[i-1].a))
				r=i;
			printf("%.2d %-10s%2d%5d%4d",r+1,d[i].c,d[i].n,d[i].s,d[i].a);
			for(j=0;j<7;j++)
				printf("%4d",d[i].t[j]);
			printf("\n");
		}
	}
	return 0;
}
