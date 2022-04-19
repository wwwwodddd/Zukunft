#include <bits/stdc++.h>
using namespace std;
int n, q, l, r, x;
pair<int, int> a[200020];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a + 1, a + n + 1);
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> l >> r >> x;
		cout << upper_bound(a + 1, a + n + 1, make_pair(x, r)) - lower_bound(a + 1, a + n + 1, make_pair(x, l)) << endl;
	}
	return 0;
}
