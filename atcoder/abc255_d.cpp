#include <bits/stdc++.h>
using namespace std;
int n, m, x;
int a[200020];
long long s[200020];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		s[i + 1] = s[i] + a[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> x;
		int p = lower_bound(a, a + n, x) - a;
		cout << s[n] - 2 * s[p] + x * (2LL * p - n) << endl;
	}
	return 0;
}
