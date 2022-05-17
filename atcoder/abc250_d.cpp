#include <bits/stdc++.h>
using namespace std;
long long n;
int v[1000020];
int s[1000020];
int main()
{
	n = 1000000;
	for (int i = 2; i <= n; i++)
	{
		if (!v[i])
		{
			for (int j = i; j <= n; j += i)
			{
				v[j] = i;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		s[i] = s[i - 1] + (v[i] == i);
	}
	cin >> n;
	long long z = 0;
	for (long long i = 1; i * i * i * i <= n; i++)
	{
		if (v[i] == i)
		{
			long long j = cbrt(n / i);
			while (j * j * j <= n / i)
			{
				j++;
			}
			while (j * j * j > n / i)
			{
				j--;
			}
			z += s[j] - s[i];
		}
	}
	cout << z << endl;
	return 0;
}