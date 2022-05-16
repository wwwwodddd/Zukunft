#include <bits/stdc++.h>
using namespace std;
long long f[20][2000];
int s[20];
vector<int> a;
int S(long long n)
{
	int z = 0;
	for (; n > 0; n /= 10)
	{
		z += (n % 10) * (n % 10);
	}
	return z;
}
long long F(long long n)
{
	long long z = n;
	int c = 0, t = 0;
	for (; n > 0; n /= 10)
	{
		s[c++] = n % 10;
	}
	for (int i = c - 1; i >= 0; i--)
	{
		for (int j = 0; j < s[i]; j++)
		{
			for (int b: a)
			{
				if (b >= t + j * j)
				{
					z -= f[i][b - t - j * j];
				}
			}
		}
		t += s[i] * s[i];
	}
	return z;
}

int main()
{
	f[0][0] = 1;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 2000; j++)
		{
			if (f[i][j])
			{
				for (int k = 0; k < 10; k++)
				{
					f[i + 1][j + k * k] += f[i][j];
				}
			}
		}
	}
	for (int i = 0; i < 2000; i++)
	{
		int t = i;
		for (int j = 0; j < 10; j++)
		{
			if (t == 1)
			{
				a.push_back(i);
				break;
			}
			t = S(t);
		}
	}
	long long x, y;
	while (scanf("%lld%lld", &x, &y), x + y)
	{
		printf("%lld\n", F(y + 1) - F(x));
	}
	return 0;
}