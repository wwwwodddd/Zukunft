#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
using namespace std;
long long d[100020];
int h[100020];
int v[100020];
int a[400020][3],tot;
int n,m,s,t1,t2;
long long ans;
struct N
{
	long long d;
	int r;
	N(int r=0,long long d=0):r(r),d(d){}
	bool operator <(const N &a)const
	{
		return a.d<d;
	}
};
void add(int x,int y,int z)
{
	tot++;
	a[tot][0]=h[x];
	a[tot][1]=y;
	a[tot][2]=z;
	h[x]=tot;
}
void dijk(int s)
{
	N u;
	int i,j;
	memset(d,0x3f,sizeof(d));
	memset(v,0,sizeof(v));
	d[s]=0;
	priority_queue<N>q;
	q.push(N(s,0));
	for(i=0;i<n;i++)
	{
		u=q.top();
		q.pop();
		if(u.d!=d[u.r])
		{
			i--;
			continue;
		}
		v[u.r]=1;
		for(j=h[u.r];j;j=a[j][0])
		{
			if(!v[a[j][1]]&&d[a[j][1]]>d[u.r]+a[j][2])
			{
				d[a[j][1]]=d[u.r]+a[j][2];
				q.push(N(a[j][1],d[a[j][1]]));
			}
		}
	}
	return;
}
int main()
{
	int i,x,y,z;
	scanf("%d %d %d %d %d",&m,&n,&s,&t1,&t2);
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	dijk(s);
	ans=min(d[t1],d[t2]);
	dijk(t1);
	ans+=d[t2];
	cout << ans;
	return 0;
}