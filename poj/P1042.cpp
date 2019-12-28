#include<iostream>
#include<queue>
using namespace std;
struct L
{
	int d,f,r;
	bool operator < (const L &a) const
	{
		if(f!=a.f)
			return f<a.f;
		return a.r<r;
	}
}x,y;
priority_queue<L>q;
int d[200],t[200],f[200];
int w[200],p[200];
int n,h,i,j,st,tm;
int fx,ans;
int main()
{
	while(scanf("%d",&n),n)
	{
		memset(p,0,sizeof(p));
		scanf("%d",&h);
		for(i=1;i<=n;i++)
			scanf("%d",&f[i]);
		for(i=1;i<=n;i++)
			scanf("%d",&d[i]);
		for(i=2;i<=n;i++)
			scanf("%d",&t[i]);
		ans=-1;
		st=h*12;
		for(i=1;i<=n;i++)
		{
			fx=0;
			while(!q.empty())
				q.pop();
			memset(w,0,sizeof(w));
			st-=t[i];
			tm=st;
			for(j=1;j<=i;j++)
			{
				x.d=d[j];
				x.f=f[j];
				x.r=j;
				q.push(x);
			}
			while(tm>0)
			{
				x=q.top();
				q.pop();
				if(x.f<=0)
				{
					w[1]+=tm;
					break;
				}
				tm--;
				fx+=x.f;
				x.f-=x.d;
				w[x.r]++;
				q.push(x);
			}
			if(fx>ans)
			{
				ans=fx;
				memcpy(p,w,sizeof(p));
			}
		}
		for(i=1;i<n;i++)
			printf("%d, ",p[i]*5);
		printf("%d\nNumber of fish expected: %d\n\n",p[n]*5,ans);
	}
	return 0;
}

