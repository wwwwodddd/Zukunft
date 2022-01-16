#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
const int inv2 = (p + 1) / 2;
int n;
long long x, s1, s2;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		s1 = (s1 + x) % p;
		s2 = (s2 + x * x) % p;
	}
	cout << (s1 * s1 % p + p - s2) * inv2 % p << endl;
	return 0;
}
