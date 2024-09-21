#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int n;
int f[1000020];
int main()
{
	f[0] = 1;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 6 && j <= i; j++)
		{
			f[i] = (f[i] + f[i - j]) % p;
		}
	}
	cout << f[n] << endl;
	return 0;
}
