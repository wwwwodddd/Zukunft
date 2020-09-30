#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, a, g;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> a >> g;
		cout << s << ' ' << a + 1 << ' ' << min(g / 5 * 6, 600) << endl;
	}
	return 0;
}