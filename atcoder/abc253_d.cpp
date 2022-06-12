#include <bits/stdc++.h>
using namespace std;
long long n, a, b, c, z;
long long F(long long n)
{
	return n * (n + 1) / 2;
}
int main()
{
	cin >> n >> a >> b;
	c = a / __gcd(a, b) * b;
	z = F(n) - F(n / a) * a - F(n / b) * b + F(n / c) * c;
	cout << z << endl;
	return 0;
}
