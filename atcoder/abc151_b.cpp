#include <bits/stdc++.h>
using namespace std;
int n, k, m, x;
int main()
{
	cin >> n >> k >> m;
	m *= n;
	for (int i = 1; i < n; i++)
	{
		cin >> x;
		m -= x;
	}
	if (m > k)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << max(m, 0) << endl;
	}
	return 0;
}
