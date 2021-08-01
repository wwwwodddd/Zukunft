#include <bits/stdc++.h>
using namespace std;
int f[1003000];
int t, n;
int main()
{
	f[0] = 1;
	for (int i = 0; i <= 1000000; i++)
	{
		if (f[i])
		{
			f[i + 2020] = 1;
			f[i + 2021] = 1;
		}
	}
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		cout << (f[n] ? "YES" : "NO") << endl;
	}
	return 0;
}