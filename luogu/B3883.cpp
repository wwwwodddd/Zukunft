#include <bits/stdc++.h>
using namespace std;
const int p = 20091119;
string s, r;
int t[120];
long long y, z;
int main()
{
	t[0] = 1;
	for (int i = 1; i < 111; i++)
	{
		t[i] = t[i - 1] * 10 % p;
	}
	cin >> s;
	for (int i = 1; i < s.size(); i++)
	{
		z = (z + 9 * t[(i - 1) / 2]) % p;
	}
	for (int i = 0; i < (s.size() + 1) / 2; i++)
	{
		y = (y * 10 + (s[i] - '0' - (i == 0))) % p;
	}
	r = s;
	for (int i = 0; i < s.size() / 2; i++)
	{
		r[r.size() - i - 1] = r[i];
	}
	if (r <= s)
	{
		z++;
	}
	cout << (z + y) % p << endl;
	return 0;
}