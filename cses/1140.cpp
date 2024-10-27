#include <bits/stdc++.h>
using namespace std;
vector<int> l;
vector<pair<int, int> > e[200020];
int n;
int a[200020];
int b[200020];
int p[200020];
long long f[200020];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d", &a[i], &b[i], &p[i]);
		l.push_back(b[i]);
	}
	sort(l.begin(), l.end());
	for (int i = 0; i < n; i++)
	{
		a[i] = lower_bound(l.begin(), l.end(), a[i]) - l.begin() + 1;
		b[i] = lower_bound(l.begin(), l.end(), b[i]) - l.begin() + 1;
		e[b[i]].push_back(make_pair(a[i], p[i]));
	}
	for (int i = 1; i <= n; i++)
	{
		f[i] = f[i - 1];
		for (pair<int, int> j : e[i])
		{
			f[i] = max(f[i], f[j.first - 1] + j.second);
		}
	}
	printf("%lld\n", f[n]);
	return 0;
}