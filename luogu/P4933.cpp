#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, z;
int a[1000];
map<int, int> g[1000];
int main()
{
	cin >> n;
	z = n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		for (int j = 0; j < i; j++)
		{
			int y = 1;
			if (g[j].find(a[i]-a[j]) != g[j].end())
			{
				y += g[j][a[i]-a[j]];
			}
			g[i][a[i]-a[j]] = (g[i][a[i]-a[j]] + y) % mod;
			z = (z + y) % mod;
		}
	}
	cout << z << endl;
	return 0;
}