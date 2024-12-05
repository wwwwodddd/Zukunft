
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
int main()
{
	cin >> n;
	a.resize(n);
	for (int &i : a)
	{
		cin >> i;
	}
	int t = 0;
	int z = 0;
	if (n == 1)
	{
		z = a[0];
	}
	{
		t = a[0];
		a[0] = 0;
		vector<int> f(n + 1);
		vector<int> g(n + 1);
		for (int i = 0; i < n; i++)
		{
			f[i + 1] = g[i] + a[i];
			g[i + 1] = max(g[i], f[i]);
		}
		z = max(z, max(f.back(), g.back()));
		a[0] = t;
	}
	{
		t = a[n - 1];
		a[n - 1] = 0;
		vector<int> f(n + 1);
		vector<int> g(n + 1);
		for (int i = 0; i < n; i++)
		{
			f[i + 1] = g[i] + a[i];
			g[i + 1] = max(g[i], f[i]);
		}
		z = max(z, max(f.back(), g.back()));
		a[n - 1] = t;
	}
	cout << z << endl;
	return 0;
}
