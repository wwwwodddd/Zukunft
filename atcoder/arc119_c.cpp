#include <bits/stdc++.h>
using namespace std;
int n;
long long s, x, z;
map<long long, int> g;
int main()
{
	g[0] = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (i & 1)
		{
			x = -x;
		}
		s += x;
		z += g[s]++;
	}
	cout << z << endl;
	return 0;
}
