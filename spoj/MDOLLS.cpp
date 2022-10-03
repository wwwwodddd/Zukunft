#include <bits/stdc++.h>
using namespace std;
int t, n;
map<int, int> f;
pair<int, int> a[20020];
void ins(int x, int y)
{
	auto it = prev(f.upper_bound(x));
	if (it->second >= y)
	{
		return;
	}
	it++;
	while (it != f.end() && it->second < y)
	{
		f.erase(it++);
	}
	f[x] = y;
}
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &a[i].first, &a[i].second);
			a[i].second = -a[i].second;
		}
		sort(a, a + n);
		f.clear();
		f[-1e9] = 0;
		for (int i = 0; i < n; i++)
		{
			ins(a[i].second, (--f.upper_bound(a[i].second))->second + 1);
		}
		printf("%d\n", f.rbegin()->second);
	}
	return 0;
}