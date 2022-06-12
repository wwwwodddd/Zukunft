#include <bits/stdc++.h>
using namespace std;
int t;
long long a, b, c, d, e;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> a >> b >> c >> d >> e;
		cout << max((min(d, e - a) - max(c, e - b) + 1), 0LL) << endl;
	}
	return 0;
}
