#include <bits/stdc++.h>
using namespace std;
int k;
long long n, x, t;
int main()
{
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> n >> x >> t;
		long long y = min(t / x, n);
		cout << y * (y - 1) / 2 + y * (n - y) << endl;
	}
	return 0;
}
