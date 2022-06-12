#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int n;
long long s, x;
int f[200020];
map<long long, int> g;
int main()
{
	cin >> n;
	f[1] = 1;
	for (int i = 1; i < n; i++)
	{
		cin >> x;
		s += x;
		f[i + 1] = f[i] * 2 % p;
		if (g.find(s) != g.end())
		{
			f[i + 1] = (f[i + 1] - f[g[s]] + p) % p;
		}
		g[s] = i;
	}
	cout << f[n] << endl;
	return 0;
}