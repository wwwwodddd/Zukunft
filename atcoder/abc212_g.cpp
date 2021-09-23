#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
long long n, c, z = 1;
long long a[50], b[50];
void dfs(int x, long long d, long long f)
{
	if (x == c)
	{
		z = (z + d * f) % p;
	}
	else
	{
		for (int i = 0; i <= b[x]; i++)
		{
			dfs(x + 1, d, f);
			d = d * a[x] % p;
			f = f * (i ? a[x] : a[x] - 1) % p;
		}
	}
}

int main()
{
	cin >> n;
	n--;
	for (long long i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			a[c] = i;
			while (n % i == 0)
			{
				b[c]++;
				n /= i;
			}
			c++;
		}
	}
	if (n > 1)
	{
		a[c] = n;
		b[c++] = 1;
	}
	dfs(0, 1, 1);
	cout << z << endl;
	return 0;
}