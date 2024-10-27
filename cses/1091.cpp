#include <bits/stdc++.h>
using namespace std;
multiset<int> s;
int n, m, x;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		s.insert(x);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> x;
		set<int>::iterator it = s.upper_bound(x);
		if (it == s.begin())
		{
			cout << -1 << endl;
		}
		else
		{
			it--;
			cout << *it << endl;
			s.erase(it);
		}
	}
	return 0;
}