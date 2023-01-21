#include <bits/stdc++.h>
using namespace std;
int n;
map<string, string> a;
set<string> b;
string s, t;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> t;
		a[s] = t;
	}
	for (auto [u, v] : a)
	{
		if (b.find(u) == b.end())
		{
			b.insert(u);
			while (v != u && a.find(v) != a.end() && b.find(v) == b.end())
			{
				b.insert(v);
				v = a[v];
			}
			if (u == v)
			{
				printf("No\n");
				return 0;
			}
		}
	}
	printf("Yes\n");
	return 0;
}