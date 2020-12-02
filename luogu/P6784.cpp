#include <bits/stdc++.h>
using namespace std;
long long a, b, c;
bool ok(long long x)
{
	return x * (x + 1) / 2 <= a + c && x * (x + 1) / 2 <= b + c && x * (x + 1) <= a + b + c;
}
int main()
{
	cin >> a >> b >> c;
	long long L = 0, R = 2e9;
	while (L < R - 1)
	{
		long long M = (L + R) / 2;
		if (ok(M))
		{
			L = M;
		}
		else
		{
			R = M;
		}
	}
	cout << L << endl;
	return 0;
}