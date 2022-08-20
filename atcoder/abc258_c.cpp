#include <bits/stdc++.h>
using namespace std;
int n, q, t, x, c;
string s;
int main()
{
	cin >> n >> q >> s;
	for (int i = 0; i < q; i++)
	{
		cin >> t >> x;
		if (t == 1)
		{
			c = (c + x) % n;
		}
		else
		{
			cout << s[(x - 1 - c + n) % n] << endl;
		}
	}
	return 0;
}
