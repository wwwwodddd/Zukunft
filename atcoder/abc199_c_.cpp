#include <bits/stdc++.h>
using namespace std;
int n, q, t, a, b, f;
string s;
int main()
{
	cin >> n >> s >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> t >> a >> b;
		a--;
		b--;
		if (t == 1)
		{
			if (f)
			{
				a = (a + n) % (2 * n);
				b = (b + n) % (2 * n);
			}
			swap(s[a], s[b]);
		}
		else
		{
			f ^= 1;
		}
	}
	if (f)
	{
		s = s.substr(n) + s.substr(0, n);
	}
	cout << s << endl;
	return 0;
}
