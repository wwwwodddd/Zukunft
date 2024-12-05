#include <bits/stdc++.h>
using namespace std;
int t, n;
vector<int> a;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		a.resize(n);
		for (int &i : a)
		{
			scanf("%d", &i);
		}
		vector<int> f(n + 1);
		vector<int> g(n + 1);
		for (int i = 0; i < n; i++)
		{
			f[i + 1] = g[i] + a[i];
			g[i + 1] = max(g[i], f[i]);
		}
		printf("%d\n", max(f.back(), g.back()));
	}
	return 0;
}
