#include<iostream>
using namespace std;
int d[205];
int g[205][205];
int r[205][205];
int c[205];
int p[205];
int n,m;
int ll,rr,ans;
int a[80020][3];
int h[205],tot;
void add(int x,int y,int z)
{
	tot++;
	a[tot][0]=h[x];
	a[tot][1]=y;
	a[tot][2]=z;
	h[x]=tot;
	return;
}
int isap(int s,int t)
{
	int re=0,i=s,j,z;
	memset(p,-1,sizeof(p));
	p[s]=s;
	while(d[s]<m)
	{
		for(j=0;j<m;j++)
			if(g[i][j]>0&&d[i]==d[j]+1)
				break;
		if(j<m)
		{
			p[j]=i;
			i=j;
			if(i==t)
			{
				z=0x7fffffff;
				for(i=t;i!=s;i=p[i])
					z=min(z,g[p[i]][i]);
				for(i=t;i!=s;i=p[i])
					g[p[i]][i]-=z,g[i][p[i]]+=z;
				re+=z;
			}
		}
		else
		{
			c[d[i]]--;
			if(c[d[i]]==0)
				return re;
			d[i]=m;
			for(j=0;j<m;j++)
				if(g[i][j]>0)
					d[i]=min(d[i],d[j]+1);
			c[d[i]]++;
			i=p[i];
		}
	}
	return re;
}
int work()
{
	int mid,i,j;
	while(ll<rr)
	{
		mid=(ll+rr)/2;
		memset(d,0,sizeof(d));
		memset(c,0,sizeof(c));
		memset(g,0,sizeof(g));
		for(i=0;i<m;i++)
			for(j=h[i];j;j=a[j][0])
				if(a[j][2]<=mid)
					g[i][a[j][1]]++;
		if(isap(0,m-1)>=ans)
			rr=mid;
		else
			ll=mid+1;
	}
	return ll;
}
int main()
{
	int i,j,x,y,z;
	ll=0x3fffffff;
	scanf("%d %d %d",&m,&n,&ans);
	memset(r,0x3f,sizeof(r));
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		ll=min(ll,z);
		rr=max(rr,z);
		add(x-1,y-1,z);
		add(y-1,x-1,z);
	}
	printf("%d",work());
	return 0;
}