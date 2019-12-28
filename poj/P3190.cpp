#include<iostream>
#include<queue>
using namespace std;
struct node
{
	int s,t,r,z;
	bool operator<(const node &a)const
	{
		return a.t<t;
	}
}a[50020],u;
int cmp1(node a,node b)
{
	return a.s<b.s;
}
int cmp2(node a,node b)
{
	return a.r<b.r;
}
int n,i,j,cnt;
priority_queue<node>q;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d",&a[i].s,&a[i].t);
		a[i].r=i;
	}
	sort(a+1,a+1+n,cmp1);
	u.s=1;
	u.t=0x3fffffff;
	u.r=u.z=0;
	q.push(u);
	for(i=1;i<=n;i++)
	{
		u=q.top();
		if(u.t<a[i].s)
		{
			a[i].z=u.z;
			q.pop();
			q.push(a[i]);
		}
		else
		{
			a[i].z=++cnt;
			q.push(a[i]);
		}
	}
	sort(a+1,a+1+n,cmp2);
	printf("%d\n",cnt);
	for(i=1;i<=n;i++)
		printf("%d\n",a[i].z);
	return 0;
}
