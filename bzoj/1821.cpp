#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<iostream>
using namespace std;
struct E{int s,t;double v;}e[500020];
int px[1020];
int py[1020];
int f[1020];
int n,m,i,j,k,tot,cnt;
bool cmp(E a,E b)
{
	return a.v<b.v;
}
int F(int x)
{
	if(f[x]==x)
		return x;
	return f[x]=F(f[x]);
}
void U(int x,int y)
{
	f[F(x)]=F(y);
}
int main()
{
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;i++)
		scanf("%d %d",&px[i],&py[i]);
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
		{
			e[tot].s=i;
			e[tot].t=j;
			e[tot].v=(px[i]-px[j]+0.0)*(px[i]-px[j])+(py[i]-py[j]+0.0)*(py[i]-py[j]);
			tot++;
		}
	cnt=n;
	sort(e,e+tot,cmp);
	for(i=0;i<=n;i++)
		f[i]=i;
	for(i=0;i<tot;i++)
	{
		if(F(e[i].s)!=F(e[i].t))
		{
			if(cnt>k)
				U(e[i].s,e[i].t),cnt--;
			else
				break;
		}
	}
	printf("%.2lf",sqrt(e[i].v));
	return 0;
}