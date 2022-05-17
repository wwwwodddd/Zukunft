#include <bits/stdc++.h>
using namespace std;
int P(int x)
{
	for (int i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			return 0;
		}
	}
	return 1;
}
int F(int n, int p)
{
	int re = 0;
	while (n > 0)
	{
		n /= p;
		re += n;
	}
	return re;
}
int main()
{
	long long z = 1;
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		if (P(i))
		{
			z = z * (F(n, i) + 1) % 1000000007;
		}
	}
	cout << z << endl;
	return 0;
}
