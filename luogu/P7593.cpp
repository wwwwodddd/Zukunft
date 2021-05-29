#include <bits/stdc++.h>
using namespace std;
int t;
long long n, k, s;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> k >> s;
		cout << ((k * (k + 1) <= s * 2 && s * 2 <= k * (n + n - k + 1)) ? "Yes" : "No") << endl;
	}
	return 0;
}