#include <bits/stdc++.h>
using namespace std;
int n, mod = 1000000007;
long long ans = 1;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		ans = ans * (i + 1) % mod;
		ans = ans * (i + 1) % mod;
		ans = ans * (i + 1) % mod;
		ans = ans * (2 * i + 1) % mod;
	}
	cout << ans << endl;
	return 0;
}
