#include <bits/stdc++.h>
using namespace std;
int n, m, s, t, a, b, l;
int main()
{
	cin >> n >> m >> t;
	s = n;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		s -= a - l;
		if (s <= 0)
		{
			cout << "No" << endl;
			return 0;
		}
		s = min(s + b - a, n);
		l = b;
	}
	s -= t - l;
	if (s <= 0)
	{
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	return 0;
}
