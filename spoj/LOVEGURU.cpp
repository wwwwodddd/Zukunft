#include <bits/stdc++.h>
using namespace std;
int n, m;
string a, b;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		set<string> s;
		for (int j = 0; j + m <= a.size(); j++)
		{
			s.insert(a.substr(j, m));
		}
		int f = 0;
		for (int j = 0; j + m <= b.size(); j++)
		{
			if (s.find(b.substr(j, m)) != s.end())
			{
				f = 1;
				break;
			}
		}
		cout << (f ? "Yes" : "No") << endl;
	}
	return 0;
}