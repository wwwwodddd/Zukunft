#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
int b[100][100],c[100],a[10000];
int i,n,m,t;
int G(int *a,int n,int x)
{
	int i,l;
	for(i=n,l=1<<6;l;l>>=1)
		if(i-l>=0&&a[i-l]>=x)
			i-=l;
	return i;
}
int C(int l,int r,int x)
{
	int L=l/100,R=r/100,re=0;
	if(L==R)
	{
		for(i=l;i<=r;i++)
			re+=a[i]<x;
		return re;
	}
	for(i=l;i<=(L+1)*100-1;i++)
		re+=a[i]<x;
	for(i=L+1;i<=R-1;i++)
		re+=G(b[i],c[i],x);
	for(i=R*100;i<=r;i++)
		re+=a[i]<x;
	return re;
}
int K(int l,int r,int x)
{
	int i,d;
	for(i=0,d=1<<30;d;d>>=1)
		if(C(l,r,i+d)<x)
			i+=d;
	return i;
}
void R(int p,int x)
{
	int P=p/100;
	b[P][lower_bound(b[P],b[P]+c[P],a[p])-b[P]]=x;
	sort(b[P],b[P]+c[P]);
	a[p]=x;
	return;
}
char o[7];
int main()
{
	int i,j,k;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		b[i/100][c[i/100]++]=a[i];
	}
	for(i=0;i<(n-1)/100+1;i++)
		sort(b[i],b[i]+c[i]);
	while(m--)
	{
		scanf("%s",o);
		if(o[0]=='C')
			scanf("%d%d",&i,&j),R(i-1,j);
		else
			scanf("%d%d%d",&i,&j,&k),printf("%d\n",K(i-1,j-1,k));
	}
	return 0;
}