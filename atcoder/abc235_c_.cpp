#include <bits/stdc++.h>
using namespace std;
int n, q, x, k;
pair<int, int> a[200020];
int main()
{
	cin >> n >> q;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first;
		a[i].second = i + 1;
	}
	sort(a, a + n);
	for (int i = 0; i < q; i++)
	{
		cin >> x >> k;
		int l = lower_bound(a, a + n, make_pair(x, 0)) - a;
		int r = upper_bound(a, a + n, make_pair(x, n)) - a;
		if (r - l < k)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << a[l + k - 1].second << endl;
		}
	}
	return 0;
}
