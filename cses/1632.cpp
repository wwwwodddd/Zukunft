#include <bits/stdc++.h>
using namespace std;
int n, k, z;
pair<int, int> a[200020];
multiset<int> s;
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		if (s.size() < k)
		{
			s.insert(a[i].second);
			z++;
		}
		else if (*s.begin() <= a[i].first)
		{
			s.erase(s.begin());
			s.insert(a[i].second);
			z++;
		}
		else
		{
			s.insert(a[i].second);
			s.erase(--s.end());
		}
	}
	cout << z << endl;
	return 0;
}