#include<stdio.h>
#include<stdlib.h>
#define LL(x) (x<<1)
#define RR(x) (x<<1|1)
#define min(a,b) a>b?b:a
int n,m,t;
int a[100010][2];
long long ans;
struct te{int l,r,u;}te[300020];
int cmp(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}
void bd(int l,int r,int d)
{
    te[d].l=l;
    te[d].r=r;
    if(te[d].l==te[d].r)
    {
        te[d].u=0;
        return ;
    }
    int mid=(te[d].l+te[d].r)>>1;
    bd(l,mid,LL(d));
    bd(mid+1,r,RR(d));
    te[d].u=te[LL(d)].u+te[RR(d)].u;
}
void ud(int x,int d)
{
    if(te[d].l==te[d].r)
    {
		te[d].u=1;
		return;
    }
    int mid=(te[d].l+te[d].r)>>1;
    if(x<=mid)
		ud(x,LL(d));
    else if(x>mid)
		ud(x,RR(d));
    te[d].u=te[LL(d)].u+te[RR(d)].u;
}
int qy(int l,int r,int d)
{
	if(l<=te[d].l&&te[d].r<=r)
		return te[d].u;
	int mid=(te[d].l+te[d].r)>>1;
	if(l>mid)
		return qy(l,r,RR(d));
	else if(r<=mid)
		return qy(l,r,LL(d));
	else
		return qy(l,r,LL(d))+qy(l,r,RR(d));
}
int main()
{
    int i,k;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",a[i]);
			a[i][1]=i;
		}
		qsort(a,n,8,cmp);
		bd(0,n-1,1);
		for(i=0;i<n;i++)
		{
			k=qy(0,a[i][1],1);
			ans+=k*(n-a[i][1]-i+k-1)+(a[i][1]-k)*(i-k);
			ud(a[i][1],1);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}