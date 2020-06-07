#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t, n, m, p;
	long long z = 1;
	cin >> t >> n >> m >> p;
	for (int i = 0; i < m; i++)
	{
		z = z * (n - m + 1 - i) % p;
	}
	cout << z << endl;
	return 0;
}