#include <bits/stdc++.h>
using namespace std;
int n;
long long t, a[100020];
int main()
{
	cin >> n >> t;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] += a[i - 1];
	}
	t %= a[n];
	int p = lower_bound(a, a + n + 1, t) - a;
	cout << p << " " << t - a[p - 1] << endl;
	return 0;
}
