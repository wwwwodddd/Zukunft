#include <bits/stdc++.h>
using namespace std;
int t, n, x;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		set<long long> v;
		v.insert(0);
		bool f = false;
		long long s = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			if (i & 1)
			{
				s += x;
			}
			else
			{
				s -= x;
			}
			f |= v.count(s);
			v.insert(s);
		}
		cout << (f ? "YES" : "NO") << endl;
	}
	return 0;
}