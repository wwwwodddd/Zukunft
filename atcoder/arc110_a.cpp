#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y)
{
	return y ? gcd(y, x % y) : x;
}
long long lcm(long long x, long long y)
{
	return x / gcd(x, y) * y;
}
int n;
int main()
{
	cin >> n;
	long long z = 1;
	for (int i = 2; i <= n; i++)
	{
		z = lcm(z, i);
	}
	cout << z + 1 << endl;
	return 0;
}
