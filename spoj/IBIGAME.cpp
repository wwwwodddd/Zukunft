#include <bits/stdc++.h>
using namespace std;
int t;
long long a, b;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> a >> b;
		a = (a - b) & 7;
		cout << (2 <= a && a <= 6 ? "Ziya" : "Farael") << endl;
	}
	return 0;
}