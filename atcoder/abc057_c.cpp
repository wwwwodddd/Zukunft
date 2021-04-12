#include <bits/stdc++.h>
using namespace std;
int F(long long x)
{
	return x > 0 ? F(x / 10) + 1 : 0;
}
int main()
{
	long long n;
	cin >> n;
	int z = 11;
	for (long long i = 1; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			z = min(z, F(n / i));
		}
	}
	cout << z << endl;
	return 0;
}