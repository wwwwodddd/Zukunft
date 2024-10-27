#include <bits/stdc++.h>
using namespace std;
string s;
int v[256], c;
int main()
{
	cin >> s;
	memset(v, -1, sizeof v);
	for (int i = 0; i < s.size(); i++)
	{
		if (v[s[i]] == -1)
		{
			v[s[i]] = c++;
		}
	}
	c--;
	vector<int> p(c, 0);
	map<vector<int>, int> g;
	g[p]++;
	long long z = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (v[s[i]] == c)
		{
			for (int &j : p)
			{
				j--;
			}
		}
		else
		{
			p[v[s[i]]]++;
		}
		z += g[p]++;
	}
	cout << z << endl;
	return 0;
}