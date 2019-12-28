#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int t[20][100020];
int c[20][100020];
int a[100020];
int b[100020];
int i,n,m,l,r,k;
bool cmp(const int &x,const int &y)
{
	return a[x]<a[y];
}
void bd(int d,int l,int r)
{
	if(l==r)
		return;
	int m=l+r>>1,cl=l,cr=m+1,cc=0;
	for(int i=l;i<=r;i++)
	{
		if(t[d][i]<=m)
			t[d+1][cl++]=t[d][i],cc++;
		else
			t[d+1][cr++]=t[d][i];
		c[d][i]=cc;
	}
	bd(d+1,l,m);
	bd(d+1,m+1,r);
}
int A(int d,int st,int ed,int l,int r,int k)
{
	if(l==r)
		return t[d][l];
	int ll=l==st?0:c[d][l-1],rr=c[d][r],m=st+ed>>1;
	if(rr-ll>=k)
		return A(d+1,st,m,st+ll,st+rr-1,k);
	else
		return A(d+1,m+1,ed,m+(l-st-ll+1),m+(r-st-rr+1),k-(rr-ll));
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i),b[i]=i;
	sort(b+1,b+1+n,cmp);
	for(int i=1;i<=n;i++)
		t[0][b[i]]=i;
	bd(0,1,n);
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&l,&r,&k);
		printf("%d\n",a[b[A(0,1,n,l,r,k)]]);
	}
	return 0;
}
