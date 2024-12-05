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
	vector<int> f(n + 1);
	vector<int> g(n + 1);
	for (int i = 0; i < n; i++)
	{
		f[i + 1] = g[i] + a[i];
		g[i + 1] = max(g[i], f[i]);
	}
	cout << max(f.back(), g.back()) << endl;
	return 0;
}
