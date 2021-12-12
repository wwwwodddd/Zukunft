#include <bits/stdc++.h>
using namespace std;
long long n, l, r;
long long F(long long r, long long n)
{
	long long z = 0;
	for (int i = 0; i < 60; i++)
	{
		if (n >> i & 1)
		{
			z += max(0LL, min(r, 1LL << i + 1) - (1LL << i));
		}
	}
	return z;
}
int main()
{
	cin >> n >> l >> r;
	cout << F(r + 1, n) - F(l, n) << endl;
	return 0;
}
