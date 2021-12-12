#include <bits/stdc++.h>
using namespace std;
int n, m, x, t = 1e9;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		m -= x;
		t = min(t, x);
	}
	cout << m / t + n << endl;
	return 0;
}
