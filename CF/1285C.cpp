#include <bits/stdc++.h>
using namespace std;
long long n;
int main()
{
	cin >> n;
	long long z = n;
	for (long long i = 1; i * i <= n; i++)
	{
		if (n % i == 0 && gcd(i, n / i) == 1)
		{
			z = n / i;
		}
	}
	cout << n / z << " " << z << endl;
	return 0;
}