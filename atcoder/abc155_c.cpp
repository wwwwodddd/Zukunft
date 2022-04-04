#include <bits/stdc++.h>
using namespace std;
int n, z;
string s;
map<string, int> g;
vector<string> a;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		g[s]++;
	}
	for (auto&i: g)
	{
		if (z < i.second)
		{
			z = i.second;
			a.clear();
		}
		if (z == i.second)
		{
			a.push_back(i.first);
		}
	}
	for (auto&i: a)
	{
		cout << i << endl;
	}
	return 0; 
}
