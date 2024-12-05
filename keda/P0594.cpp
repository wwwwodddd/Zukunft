#include <bits/stdc++.h>
using namespace std;
int n, m, d;
string s;
map<pair<int, int>, vector<string> > g;
bool cmp(const string &a, const string &b)
{
	if (a.size() != b.size())
	{
		return a.size() < b.size();
	}
	return a < b;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> m >> d;
		g[{m, d}].push_back(s);
	}
	int cnt = 0;
	for (auto &i : g)
	{
		if (i.second.size() > 1)
		{
			cnt++;
			cout << i.first.first << ' ' << i.first.second;
			sort(i.second.begin(), i.second.end(), cmp);
			for (const string &j : i.second)
			{
				cout << ' ' << j;
			}
			cout << endl;
		}
	}
	if (cnt == 0)
	{
		cout << "None" << endl;
	}
	return 0;
}