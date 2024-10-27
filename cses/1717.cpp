#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int n;
int f[1000020];
int main()
{
	cin >> n;
	f[0] = 1;
	f[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		f[i] = (f[i - 1] + f[i - 2]) * (i - 1LL) % p;
	}
	cout << f[n] << endl;
	return 0;
}