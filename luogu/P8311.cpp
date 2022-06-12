#include <bits/stdc++.h>
using namespace std;
int n, x, r = 1e9;
long long s;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		s += x;
		r = min(r, x);
	}
	cout << r * (n - 2LL) + s << endl;
	return 0;
}
