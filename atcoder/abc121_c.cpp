#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<int, int> a[100020];
long long z;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		long long u = min(m, a[i].second);
		z += u * a[i].first;
		m -= u;
	}
	cout << z << endl;
	return 0;
}
