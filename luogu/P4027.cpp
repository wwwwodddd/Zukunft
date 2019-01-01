#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 100003
#define eps 1e-9
#define inf 1000000000
using namespace std;
int n,m,st[N];
double f[N];
struct data
{
   double a,b,rate;
   double k;
   int pos;	
}a[N],np[N];
struct point
{
	double x,y;
	bool operator <(const point &b)const
	{
		return (x<b.x+eps||fabs(x-b.x)<=eps&&y<b.y+eps);
	}
}p[N],np1[N];
int cmp(data a,data b)
{
	return a.k<b.k;
}
double getk(int i,int j)
{
	//if (i==0)  return -inf;
	//if (j==0)  return inf;
	if (fabs(p[i].x-p[j].x)<=eps)  return -inf;
	return (p[i].y-p[j].y)/(p[i].x-p[j].x);
}
void divide(int l,int r)
{
	if (l==r)
	{
		f[l]=max(f[l-1],f[l]);
		p[l].x=(f[l]*a[l].rate)/(a[l].rate*a[l].a+a[l].b);
		p[l].y=f[l]/(a[l].rate*a[l].a+a[l].b);
		return;
	}
	int mid=(l+r)/2;
	int l1=l,l2=mid+1;
	for (int i=l;i<=r;i++)
	 if (a[i].pos<=mid)  np[l1++]=a[i];
	 else np[l2++]=a[i];
	for (int i=l;i<=r;i++) a[i]=np[i];
	divide(l,mid);
	int top=0;
	for (int i=l;i<=mid;i++)
	 {
	 	while (top>=2&&getk(i,st[top])+eps>getk(st[top],st[top-1]))  top--;
	 	st[++top]=i;
	 }
	int j=1;
	for (int i=r;i>=mid+1;i--)
	 {
	 	while (j<top&&getk(st[j],st[j+1])+eps>a[i].k) j++;
	 	int k=st[j];
	 	f[a[i].pos]=max(f[a[i].pos],p[k].x*a[i].a+p[k].y*a[i].b);
	 }
	divide(mid+1,r);
	l1=l; l2=mid+1;
	for (int i=l;i<=r;i++)
	 if((p[l1]<p[l2]||l2>r)&&l1<=mid)  np1[i]=p[l1++];
	 else np1[i]=p[l2++];
	for (int i=l;i<=r;i++)
	  p[i]=np1[i];
}
int main()
{
	scanf("%d%lf",&n,&f[0]);
	for (int i=1;i<=n;i++)
	 {
	 	scanf("%lf%lf%lf",&a[i].a,&a[i].b,&a[i].rate);
	 	a[i].pos=i;
	 	a[i].k=-a[i].a/a[i].b;
	 }
	sort(a+1,a+n+1,cmp);
	divide(1,n);
	printf("%0.3lf\n",f[n]);
}