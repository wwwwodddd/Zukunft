#include <stdio.h>
#include <iostream>
#define L a[0]
#define R a[1]
using namespace std;
struct N *h, *O, *rt, *tt;
struct N
{
	int w, sz, rv;
	N *f, *a[2];
	int d()
	{
		return f->R == this;
	}
	void sc(N *y, int z)
	{
		a[z] = y;
		y->f = this;
	}
	void rev()
	{
		if (this == O)
		{
			return;
		}
		swap(L, R);
		rv ^= 1;
	}
	void pd()
	{
		if (this == O)
		{
			return;
		}
		if (rv)
		{
			L->rev();
			R->rev();
			rv = 0;
		}
	}
	void ud()
	{
		if (this == O)
		{
			return;
		}
		sz = L->sz + R->sz + 1;
	}
	void rtt()
	{
		int c = d();
		N *p = f;
		p->pd();
		pd();
		p->sc(a[!c], c);
		p->f->sc(this, p->d());
		sc(p, !c);
		if (rt == p)
		{
			rt = this;
		}
		p->ud();
	}
	void spy(N *y)
	{
		for (pd(); f != y;)
		{
			if (f->f == y)
			{
				rtt();
			}
			else
			{
				if (d() == f->d())
				{
					f->rtt();
				}
				else
				{
					rtt();
				}
				rtt();
			}
		}
		ud();
	}
} t[100020];
int a[100020];
N *cal(int k)
{
	N *z = ++tt;
	z->w = k;
	z->sz = 1;
	z->rv = 0;
	z->f = z->R = z->L = O;
	return z;
}
void sct(int k, N *f)
{
	N *p;
	for (p = rt;;)
	{
		p->pd();
		int j = p->L->sz;
		if (j == k)
		{
			break;
		}
		p = p->a[k > j];
		if (k > j)
		{
			k -= j + 1;
		}
	}
	p->spy(f);
}
N *mt(int l, int r, N *f)
{
	if (l > r)
	{
		return O;
	}
	int mid = (l + r) >> 1;
	N *x = cal(a[mid]);
	x->sc(mt(l, mid - 1, x), 0);
	x->sc(mt(mid + 1, r, x), 1);
	x->ud();
	return x;
}
void init()
{
	O = cal(0);
	O->sz = 0;
	rt = cal(0);
	rt->sc(cal(0), 1);
	rt->ud();
}
N *get(int l, int r)
{
	sct(l - 1, O);
	sct(r + 1, rt);
	return rt->R->L;
}
int n, m;
void print(N *x)
{
	if (x == O)
	{
		return;
	}
	x->pd();
	print(x->L);
	if (1 <= x->w && x->w <= n)
	{
		printf("%d ", x->w);
	}
	print(x->R);
	return;
}
int main()
{
	tt = t;
	scanf("%d%d", &n, &m);
	init();
	for (int i = 0; i < n + 5; i++)
	{
		a[i] = i;
	}
	rt->R->sc(mt(1, n, rt->R), 0);
	rt->R->L->spy(O);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		get(x, y)->rev();
	}
	print(rt);
	return 0;
}