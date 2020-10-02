#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a[100020];
int L[100020];
int R[100020];
int s[100020], ss;
int sz[100020];
char z[100020];
set<pair<int, int> > op[100020];

long long tsz[400020];
long long sm[400020];
int tmd[400020];
void build(int x, int l, int r)
{
	if (l + 1 == r)
	{
		tsz[x] = 1;
		return;
	}
	int m = (l + r) / 2;
	build(2 * x, l, m);
	build(2 * x + 1, m, r);
	tsz[x] = tsz[2 * x] + tsz[2 * x + 1];
}
void push(int x)
{
	tmd[2 * x] += tmd[x];
	sm[2 * x] += tsz[2 * x] * tmd[x];
	tmd[2 * x + 1] += tmd[x];
	sm[2 * x + 1] += tsz[2 * x + 1] * tmd[x];
	tmd[x] = 0;
}
void change(int x, int l, int r, int L, int R, int v)
{
	// if (x == 1)
	// printf("change %d %d %d %d %d %d\n", x, l, r, L, R, v);
	if (r <= L || R <= l)
	{
		return;
	}
	if (L <= l && r <= R)
	{
		tmd[x] += v;
		sm[x] += tsz[x] * v;
		return;
	}
	push(x);
	int m = (l + r) / 2;
	change(2 * x, l, m, L, R, v);
	change(2 * x + 1, m, r, L, R, v);
	sm[x] = sm[2 * x] + sm[2 * x + 1];
}
long long query(int x, int l, int r, int L,int R)
{
	// printf("query %d %d %d %d %d\n", x, l, r, L, R);
	if (r <= L || R <= l)
	{
		return 0;
	}
	if (L <= l && r <= R)
	{
		return sm[x];
	}
	push(x);
	int m = (l + r) / 2;
	return query(2 * x, l, m, L, R) + query(2 * x + 1, m, r, L, R);
}

void dfs(int x, int y)
{
	L[x] = ss;
	s[ss++] = x;
	sz[x] = 1;
	for (int i : a[x])
	{
		if (i != y)
		{
			dfs(i, x);
			sz[x] += sz[i];
		}
	}
	R[x] = ss;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0);
	build(1, 0, n);
	for (int i = 0; i < m; i++)
	{
		int x, y, o;
		scanf("%d", &o);
		if (o == 1)
		{
			scanf("%d%d", &x, &y);
			set<pair<int, int> >::iterator it = op[y].upper_bound(make_pair(L[x], R[x]));
			if (it != op[y].begin())
			{
				if ((--it)->second >= R[x])
				{
					continue;
				}
			}
			set<pair<int, int> >::iterator it = op[y].upper_bound(make_pair(L[x], R[x]));
			while (true)
			{
				if (it == op[y].end() || R[x] <= it->first)
				{
					break;
				}
				change(1, 0, n, it->first, it->second, -1);
				op[y].erase(it++);
			}
			change(1, 0, n, L[x], R[x], 1);
			op[y].insert(make_pair(L[x], R[x]));
		}
		else
		{
			scanf("%d", &x);
			printf("%lld\n", query(1, 0, n, L[x], R[x]));
		}
	}
	return 0;
}
