#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int n, m;
int a[200020];
int v[200020];
long long x = 1, y = 1;
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		x = x * m % p;
		if (!v[i])
		{
			y = y * m % p;
			for (int j = i; !v[j]; j = a[j])
			{
				v[j] = 1;
			}
		}
	}
	cout << (x - y + p) * 499122177 % p << endl;
	return 0;
}