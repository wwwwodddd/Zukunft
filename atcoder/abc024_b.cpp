#include <bits/stdc++.h>
using namespace std;
int n, t, x, s, l;
int main()
{
	cin >> n >> t;
	l = -1e9;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		s += min(x - l, t);
		l = x;
	}
	cout << s << endl;
	return 0;
}
