#include<stdio.h>
#define LL(x) x<<1
#define RR(x) x<<1|1
struct TR
{
int r,l,n;
}t[24000];
int f[8020];
int s[8020];
void build(int l,int r,int idx)
{
	t[idx].l=l;
	t[idx].r=r;
	t[idx].n=r-l+1;
	if(l==r)
		return;
	int mid=(l+r)/2;
	build(l,mid,LL(idx));
	build(mid+1,r,RR(idx));

	return;
}
int query(int x,int idx)
{
	t[idx].n--;
	if(t[idx].l==t[idx].r)
		return t[idx].l;
	if(t[LL(idx)].n>=x)
		return query(x,LL(idx));
	else
		return query(x-t[LL(idx)].n,RR(idx));

}
int main()
{
	int n,i;
	scanf("%d",&n);
	build(1,n,1);
	for(i=2;i<=n;i++)
		scanf("%d",&f[i]);
	for(i=n;i>0;i--)
		s[i]=query(f[i]+1,1);
	for(i=1;i<=n;i++)
		printf("%d\n",s[i]);
	return 0;
}