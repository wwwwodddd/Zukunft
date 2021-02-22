#include <bits/stdc++.h>
using namespace std;
int t, n;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		cout << (n - 1LL) / 2 * n + 1 - n % 2 << endl;
	}
	return 0;
}