#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a[100020];
int b[100020];
int f[100020];
int l[100020];
int s[100020];
int L[100020];
int R[100020];
int ss, x;
int sm[400020];
int sa[400020];
void sam(int x, int l, int r, int v) {
	sm[x] = (r - l) * v;
	sa[x] = v;
}
void push(int x, int l, int r) {
	if (~sa[x])
	{
		int mid = (l + r) / 2;
		sam(x * 2, l, mid, sa[x]);
		sam(x * 2 + 1, mid, r, sa[x]);
		sa[x] = -1;
	}
}
void change(int x, int l, int r, int L, int R, int v) {
	if (r <= L || R <= l) {
		return;
	}
	if (L <= l && r <= R) {
		sam(x, l, r, v);
		return;
	}
	push(x, l, r);
	int mid = (l + r) / 2;
	change(x * 2, l, mid, L, R, v);
	change(x * 2 + 1, mid, r, L, R, v);
	sm[x] = sm[x * 2] + sm[x * 2 + 1];
}
int query(int x, int l, int r, int L, int R) {
	if (r <= L || R <= l) {
		return 0;
	}
	if (L <= l && r <= R) {
		return sm[x];
	}
	push(x, l, r);
	int mid = (l + r) / 2;
	return query(x * 2, l, mid, L, R) + query(x * 2 + 1, mid, r, L, R);
}
void dfs(int x, int y)
{
	s[x] = 1;
	f[x] = y;
	for (int i: a[x])
	{
		dfs(i, x);
		s[x] += s[i];
		if (!b[x] || s[b[x]] < s[i])
		{
			b[x] = i;
		}
	}
}
void dfs2(int x, int y)
{
	l[x] = y;
	L[x] = ss++;
	if (b[x] > 0)
	{
		dfs2(b[x], y);
	}
	for (int i: a[x])
	{
		if (i != b[x])
		{
			dfs2(i, i);
		}
	}
	R[x] = ss;
}
int main()
{
	scanf("%d", &n);
	for (int i = 2; i <= n; i++)
	{
		scanf("%d", &x);
		a[x + 1].push_back(i);
	}
	dfs(1, 0);
	dfs2(1, 1);
	memset(sa, -1, sizeof sa);
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		char o[20];
		scanf("%s%d", o, &x);
		x++;
		int s = sm[1];
		if (*o == 'i')
		{
			for (; x != 0; x = f[l[x]])
			{
				change(1, 0, n, L[l[x]], L[x] + 1, 1);
			}
			printf("%d\n", sm[1] - s);
		}
		else
		{
			change(1, 0, n, L[x], R[x], 0);
			printf("%d\n", s - sm[1]);
		}
	}
	return 0;
}