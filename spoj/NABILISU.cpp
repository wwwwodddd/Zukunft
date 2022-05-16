#include <bits/stdc++.h>
using namespace std;
int t, a, b, k;
int main()
{
	cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		cin >> a >> b >> k;
		cout << "Case " << tt << ": " << (a == b + k && k > 0 ? "YES" : "NO") << endl;
	}
	return 0;
}