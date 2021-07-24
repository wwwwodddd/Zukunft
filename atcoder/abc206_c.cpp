#include <bits/stdc++.h>
using namespace std;
int n, x;
long long z;
map<int, int> g;
int main()
{
	cin >> n;
	z = n * (n - 1LL) / 2;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		z -= g[x]++;
	}
	cout << z << endl;
	return 0;
}
