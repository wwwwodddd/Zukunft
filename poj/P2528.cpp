#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define L(x) (x<<1)
#define R(x) (x<<1|1)
#define min(a,b) a>b?b:a
int n,m,c,ans;
int a[100010];
int v[100010];
struct tr{int l,r,c;} tr[600030];
inline int mg(int x,int y)
{
	if(x!=y)
		return -1;
	return x;
}
void bd(int l,int r,int idx)
{
    tr[idx].l=l;
    tr[idx].r=r;
    if(tr[idx].l==tr[idx].r)
    {
        tr[idx].c=0;
        return;
    }
    int mid=(tr[idx].l+tr[idx].r)>>1;
    bd(l,mid,L(idx));
    bd(mid+1,r,R(idx));
    tr[idx].c=mg(tr[L(idx)].c,tr[R(idx)].c);
}
void ud(int l,int r,int idx)
{
    if(l<=tr[idx].l&&tr[idx].r<=r)
	{
		tr[idx].c=tr[R(idx)].c=tr[L(idx)].c=c;
		return;
	}
	if((tr[idx].c&1)==0)
		tr[R(idx)].c=tr[L(idx)].c=tr[idx].c;
    int mid=(tr[idx].l+tr[idx].r)>>1;
    if(l>mid)
		ud(l,r,R(idx));
    else if(r<=mid)
		ud(l,r,L(idx));
    else 
		ud(l,r,R(idx)),ud(l,r,L(idx));
    tr[idx].c=mg(tr[L(idx)].c,tr[R(idx)].c);
    return;
}
int qy(int l,int r,int idx)
{
    if(tr[idx].c!=-1&&v[tr[idx].c])
	{
        v[tr[idx].c]=1;
		ans++;
	}
	int mid=(tr[idx].l+tr[idx].r)>>1;
    if(l>mid)
        return qy(l,r,R(idx));
    else if(r<=mid)
        return qy(l,r,L(idx));
    else 
        return qy(l,mid,L(idx))|qy(mid+1,r,R(idx));
}

int main()
{
    int i,j,k,t,x,y;
	scanf("%d",&t);
    scanf("%d",&m);
	bd(1,n,1);
	while(m--)
    {
        scanf("%d %d %d",&x,&y,&c);
        if(x>y)
        	x^=y,y^=x,x^=y;
		ud(x,y,1);	
	}
	qy(1,n,1);
	printf("%d\n",ans);
    return 0;
}

