#include <bits/stdc++.h>
using namespace std;
int n, m, t, a, b;
string s;
bool f;
int main()
{
	cin >> n >> s >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> t >> a >> b;
		a--;
		b--;
		if (t == 1)
		{
			if (f)
			{
				a += (a < n ? n : -n);
				b += (b < n ? n : -n);
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
