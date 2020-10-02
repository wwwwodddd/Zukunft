#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a[100020];
int L[100020];
int R[100020];
int ss;
set<pair<int, int> > op[100020];
long long sm[400020];
int ad[400020];
void add(int x, int l, int r, int v)
{
	ad[x] += v;
	sm[x] += v * (r - l);
}
void push(int x, int l, int r)
{
	int m = (l + r) / 2;
	if (ad[x] > 0)
	{
		add(2 * x, l, m, ad[x]);
		add(2 * x + 1, m, r, ad[x]);
		ad[x] = 0;
	}
}
void change(int x, int l, int r, int L, int R, int v)
{
	if (r <= L || R <= l)
	{
		return;
	}
	if (L <= l && r <= R)
	{
		add(x, l, r, v);
		return;
	}
	push(x, l, r);
	int m = (l + r) / 2;
	change(2 * x, l, m, L, R, v);
	change(2 * x + 1, m, r, L, R, v);
	sm[x] = sm[2 * x] + sm[2 * x + 1];
}
long long query(int x, int l, int r, int L,int R)
{
	if (r <= L || R <= l)
	{
		return 0;
	}
	if (L <= l && r <= R)
	{
		return sm[x];
	}
	push(x, l, r);
	int m = (l + r) / 2;
	return query(2 * x, l, m, L, R) + query(2 * x + 1, m, r, L, R);
}
void dfs(int x, int y)
{
	L[x] = ss++;
	for (int i : a[x])
	{
		if (i != y)
		{
			dfs(i, x);
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
			it = op[y].upper_bound(make_pair(L[x], R[x]));
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