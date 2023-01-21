#include <bits/stdc++.h>
using namespace std;
set<string> t;
string s, r;
int f[200020];
int z;
int main()
{
	while (cin >> r, r != ".")
	{
		t.insert(r);
	}
	while (cin >> r)
	{
		s += r;
	}
	f[0] = 1;
	for (int i = 0; i < s.size(); i++)
	{
		if (!f[i])
		{
			continue;
		}
		for (int l = 1; l <= 10 && i + l <= s.size(); l++)
		{
			if (t.find(s.substr(i, l)) != t.end())
			{
				f[i + l] = 1;
				z = max(z, i + l);
			}
		}
	}
	cout << z << endl;
	return 0;
}
