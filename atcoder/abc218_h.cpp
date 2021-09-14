#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200020];
int l[200020];
int r[200020];
set<pair<int, int> > s; 
long long z;
void del(int x)
{
	r[l[x]] = r[x];
	l[r[x]] = l[x];
}
int main()
{
	scanf("%d%d", &n, &m);
	m = min(m, n - m);
	for (int i = 1; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	if (n % 2 == 0)
	{
		n++;
	}
	for (int i = 1; i <= n + 1; i++)
	{
		l[i] = i - 1;
		r[i - 1] = i;
	}
	for (int i = 0; i <= n; i++)
	{
		s.insert(make_pair(a[i] + a[i + 1], i));
	}
	for (int i = 0; i < m; i++)
	{
		z += s.rbegin()->first;
		int p = s.rbegin()->second;
		int lp = l[p];
		s.erase(--s.end());
		s.erase(make_pair(a[r[p]] + a[r[r[p]]], r[p]));
		s.erase(make_pair(a[l[p]] + a[p], l[p]));
		del(r[p]);
		del(p);
		s.insert(make_pair(a[lp] + a[r[lp]], lp));
	}
	printf("%lld\n", z);
	return 0;
}