#include <bits/stdc++.h>
using namespace std;
int n, t, z, zi;
string s;
set<string> v;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> s >> t;
		if (v.insert(s).second)
		{
			if (z < t)
			{
				z = t;
				zi = i;
			}
		}
	}
	cout << zi << endl;
	return 0;
}
