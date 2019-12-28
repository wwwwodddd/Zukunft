#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int v[100020];
struct P
{
	int r;
	double d;
}d1[100020],d2[100020];
double xa,xb,ya,yb;
double s,x,y;
int i,j,k,n,t;
int tp,dn,ans,cnt;
int cmp(const void *a,const void *b)
{
	if(((P*)a)->d>((P*)b)->d)
		return 1;
	return -1;
}
int max(int x,int y)
{
	return x>y?x:y;
}
int main()
{
	while(scanf("%d",&n)&&n)
	{
		ans=0;
		scanf("%lf%lf%lf%lf%lf",&xa,&ya,&xb,&yb,&s);
		s/=3.141;
		for(i=1;i<=n;i++)
		{
			scanf("%lf %lf",&x,&y);
			d1[i].r=i;
			d2[i].r=i;
			d1[i].d=(x-xa)*(x-xa)+(y-ya)*(y-ya);
			d2[i].d=(x-xb)*(x-xb)+(y-yb)*(y-yb);
			v[i]=1;
		}
		qsort(d1+1,n,sizeof(P),cmp);
		qsort(d2+1,n,sizeof(P),cmp);
		tp=n;
		cnt=n;
		dn=0;
		while(tp!=-1&&dn!=n+2)
		{
			if(d1[tp].d+d2[dn].d>s)
			{
				if(v[d1[tp].r]==1)
					cnt--;
				v[d1[tp].r]--;
				tp--;
			}
			else
			{
				ans=max(ans,cnt);
				dn++;
				if(v[d2[dn].r]==0)
					cnt++;
				v[d2[dn].r]++;
			}
		}
		printf("%d. %d\n",++t,n-ans);
	}
	return 0;
}
