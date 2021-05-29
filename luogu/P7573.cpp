#include <bits/stdc++.h>
using namespace std;
int t, n;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		cout << (n > 1 ? (n + 1) / 2 : 0) << endl;
	}
	return 0;
}