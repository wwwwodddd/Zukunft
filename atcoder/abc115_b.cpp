#include <bits/stdc++.h>
using namespace std;
int n, x, s, m;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		s += x;
		m = max(m, x);
	}
	cout << s - m / 2 << endl;
	return 0;
}
