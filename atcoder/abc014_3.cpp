#include <bits/stdc++.h>
using namespace std;
int n, x, y, s, z;
map<int, int> g;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		g[x]++;
		g[y + 1]--;
	}
	for (auto i : g)
	{
		s += i.second;
		z = max(z, s);
	}
	cout << z << endl;
	return 0;
}
