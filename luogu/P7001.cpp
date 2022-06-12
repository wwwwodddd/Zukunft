#include <bits/stdc++.h>
using namespace std;
bool cmp(string s, string t)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != '*' && s[i] != t[i])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	string s, t;
	vector<string> z;
	int n;
	cin >> s >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		if (cmp(s, t))
		{
			z.push_back(t);
		}
	}
	cout << z.size() << endl;
	for (auto i: z)
	{
		cout << i << endl;
	}
	return 0;
}
