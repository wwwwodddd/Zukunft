#include <bits/stdc++.h>
using namespace std;
int t, x, y;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> x >> y;
		cout << min(3 * x, 2 * y) << endl;
	}
	return 0;
}