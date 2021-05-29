#include <bits/stdc++.h>
using namespace std;
const int n = 6000000;
int v[n + 1];
long long z;
int c[n + 1];
void F(int p)
{
	for (int i = 0; i < p; i++)
	{
		c[i] = 0;
	}
	for (int i = 1; i < p; i++)
	{
		c[(long long)i * i % p * i % p] += 1;
	}
	int y = 0;
	for (int i = 1; i < p; i++)
	{
		y += c[(long long)i * i % p * i % p - 1];
	}
	z += (p - 1LL) * y;
}
int main()
{
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
	for (int i = n; i > 1; i--)
	{
		if (i % 100 == 0)
		{
			cout << i << ' ' << z << endl;
		}
		if (v[i] == i)
		{
			F(i);
		}
	}
	cout << z << endl;
	freopen("753", "w", stdout);
	cout << z << endl;
	fclose(stdout);
	return 0;
}