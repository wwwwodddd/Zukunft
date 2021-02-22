#include <bits/stdc++.h>
using namespace std;
long long F(int n)
{
	long long z = 0;
	for (long long i = 1, j; i <= n; i = j + 1)
	{
		j = n / (n / i);
		z += n / i * (j - i + 1LL) * (i + j) / 2;
	}
	return z;
}
int main()
{
	int x, y;
	cin >> x >> y;
	cout << F(y) - F(x - 1) << endl;
}