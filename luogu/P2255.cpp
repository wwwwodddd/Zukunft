#include <bits/stdc++.h>
using namespace std;
int n, z;
pair<int, int> a[200];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a + n);
	multiset<int> s;
	s.insert(0);
	s.insert(0);
	for (int i = 0; i < n; i++)
	{
		if (*s.begin() <= a[i].first)
		{
			s.erase(s.begin());
			s.insert(a[i].second);
			z++;
		}
		else if (*--s.end() > a[i].second)
		{
			s.erase(--s.end());
			s.insert(a[i].second);
		}
	}
	cout << z << endl;
	return 0;
}