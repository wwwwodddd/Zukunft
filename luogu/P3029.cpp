#include <bits/stdc++.h>
using namespace std;
set<int> s;
map<int, int> c;
int n, cnt, z = 1e9;
pair<int, int> a[50020];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i].second;
		s.insert(a[i].second);
	}
	sort(a, a + n);
	for (int i = 0, j = 0; i < n;)
	{
		while (j < n && cnt < s.size())
		{
			cnt += !c[a[j++].second]++;
		}
		if (cnt == s.size())
		{
			z = min(z, a[j-1].first - a[i].first);
		}
		cnt -= !--c[a[i++].second];
	}
	printf("%d\n", z);
	return 0;
}