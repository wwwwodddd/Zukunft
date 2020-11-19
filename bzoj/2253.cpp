#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
struct B
{
	int x,y,z;
	void init(int *a)
	{
		sort(a,a+3);
		x=a[0];
		y=a[1];
		z=a[2];
	}
	bool operator<(const B &a)const
	{
		if(x!=a.x)
			return x<a.x;
		if(y!=a.y)
			return y>a.y;
		return z>a.z;
	}
	bool pre(const B &a)const
	{
		return x<a.x&&y<a.y&&z<a.z;
	}
}b[50020];
int f[50020];
namespace XLk
{
	struct Ls
	{
		int a[50020];
		int n;
		void clr()
		{
			n=0;
		}
		void add(int x)
		{
			a[n++]=x;
		}
		void doit()
		{
			sort(a,a+n);
			n=unique(a,a+n)-a;
		}
		void Q(int &x)
		{
			x=lower_bound(a,a+n,x)-a;
		}
	};
	struct BIT
	{
		int a[50020];
		int n;
		void init(int _n)
		{
			n=_n;
			fr(i,n+1)
				a[i]=-1;
		}
		void R(int x,int y)
		{
			for(x++;x<=n;x+=x&-x)
				a[x]=max(a[x],y);
		}
		int G(int x)
		{
			int re=-1;
			for(x++;x;x-=x&-x)
				re=max(re,a[x]);
			return re;	
		}
	};
	Ls lx,ly;
	BIT bit;
	struct qy
	{
		int y,*f;
		qy *nx;
		void set(int _y,int *_f)
		{
			y=_y;
			f=_f;	
		}
	};
	qy qys[50020];
	int nq;
	qy *hq[50020];
	struct pt
	{
		int y,w;
		pt *nx;
		void set(int _y,int _w)
		{
			y=_y;
			w=_w;	
		}
	};
	pt pts[50020];
	int np;
	pt *hp[50020];
	void startview()
	{
		lx.clr();
		ly.clr();
	}
	void view(int x,int y)
	{
		lx.add(x);
		ly.add(y);
	}
	void startadd()
	{
		lx.doit();
		ly.doit();
		np=nq=0;
		fr(i,lx.n)
		{
			hp[i]=0;
			hq[i]=0;
		}
	}
	void addqy(int x,int y,int *f)
	{
		qy *q=qys+nq++;
		lx.Q(x);
		ly.Q(y);
		x--,y--;
		if(x<0||y<0)
			return;
		q->set(y,f);
		q->nx=hq[x];
		hq[x]=q;
	}
	void addpt(int x,int y,int w)
	{
		pt *p=pts+np++;
		lx.Q(x);
		ly.Q(y);
		p->set(y,w);
		p->nx=hp[x];
		hp[x]=p;
	}
	void solve()
	{
		bit.init(ly.n);
		fr(i,lx.n)
		{
			for(pt *cur=hp[i];cur;cur=cur->nx)
			{
				bit.R(cur->y,cur->w);
			}
			for(qy *cur=hq[i];cur;cur=cur->nx)
			{
				int u=bit.G(cur->y)+1;
				*cur->f=max(*cur->f,u);
			}
		}
	}
}
void work(int l,int r)
{
	if(l+1==r)
	{
		return;
	}
	int m=l+r>>1;
	work(l,m);
	XLk::startview();
	for(int i=l;i<m;i++)
		XLk::view(b[i].y,b[i].z);
	XLk::startadd();
	for(int i=l;i<m;i++)
		XLk::addpt(b[i].y,b[i].z,f[i]);
	for(int i=m;i<r;i++)
		XLk::addqy(b[i].y,b[i].z,f+i);
	XLk::solve();
	work(m,r);
}
int main()
{
	int base,mod,n;
	cin>>base>>mod>>n;
	long long cur=1;
	int w[3];
	fr(i,n)
	{
		fr(j,3)
			w[j]=((cur*=base)%=mod);
		b[i].init(w);
	}
	sort(b,b+n);
	fill(f,f+n,1);
	work(0,n);
	cout<<*max_element(f,f+n)<<endl;
	return 0;
}
