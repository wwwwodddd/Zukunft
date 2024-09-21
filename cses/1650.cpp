#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
long long s[200020];
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
		s[i] ^= s[i - 1];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		cout << (s[y] ^ s[x - 1]) << endl;
	}
	return 0;
}