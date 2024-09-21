#include <bits/stdc++.h>
using namespace std;
map<long long, int> g;
int n;
long long z, s, x, a;
int main()
{
	cin >> n >> x;
	g[s]++;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		s += a;
		z += g[s - x];
		g[s]++;
	}
	cout << z << endl;
	return 0;
}