#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[120];
int m, e, n, x, f, c, z;
int main()
{
	cin >> m >> e >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> f >> c;
		a[i] = make_pair(c + e - x, f);
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		int t = min(m, a[i].second);
		z += t * a[i].first;
		m -= t;
	}
	cout << z << endl;
	return 0;
}