#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> a;
int q, l, r;
int main()
{
	cin >> s;
	a.resize(s.size() + 1);
	for (int i = 0; i < s.size(); i++)
	{
		int x = 0;
		if (s[i] == 'C')
		{
			x = 1;
		}
		else if (s[i] == 'O')
		{
			x = 2;
		}
		else if (s[i] == 'W')
		{
			x = 3;
		}
		a[i + 1] = a[i] ^ x;
	}
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> l >> r;
		cout << ((a[r] ^ a[l - 1]) == 1 ? 'Y' : 'N');
	}
	return 0;
}