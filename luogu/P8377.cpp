#include <bits/stdc++.h>
using namespace std;
int f[24];
int t, n;
int main()
{
	f[1] = 1;
	for (int i = 2; i < 24; i++)
	{
		f[i] = (f[i - 1] + f[i - 2]) % 9;
	}
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		cout << (f[(n + 2) % 24] + 8) % 9 << endl;
	}
	return 0;
}
