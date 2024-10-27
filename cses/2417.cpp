#include <bits/stdc++.h>
using namespace std;
const int m = 1000000;
int n, x;
long long c[1000020];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		c[x]++;
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = i + i; j <= m; j += i)
		{
			c[i] += c[j];
		}
	}
	for (int i = 1; i <= m; i++)
	{
		c[i] = c[i] * (c[i] - 1) / 2;
	}
	for (int i = m; i > 0; i--)
	{
		for (int j = i + i; j <= m; j += i)
		{
			c[i] -= c[j];
		}
	}
	cout << c[1] << endl;
	return 0;
}