#include <bits/stdc++.h>
using namespace std;
int n;
int t[300020][26], tt;
int v[300020];
void insert(const string &s)
{
	int p = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (t[p][s[i] - 'a'] == 0)
		{
			t[p][s[i] - 'a'] = ++tt;
		}
		p = t[p][s[i] - 'a'];
	}
	v[p] = 1;
}
bool ok(const string &s)
{
	vector<int> a[26];
	int d[26] = {};
	int p = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (v[p])
		{
			return false;
		}
		for (int j = 0; j < 26; j++)
		{
			if (t[p][j] && j != s[i] - 'a')
			{
				a[j].push_back(s[i] - 'a');
				d[s[i] - 'a']++;
			}
		}
		p = t[p][s[i] - 'a'];
	}
	queue<int> q;
	for (int i = 0; i < 26; i++)
	{
		if (d[i] == 0)
		{
			q.push(i);
		}
	}
	int c = 0;
	while (q.size())
	{
		c++;
		int u = q.front();
		q.pop();
		for (int i : a[u])
		{
			if (!--d[i])
			{
				q.push(i);
			}
		}
	}
	return c == 26;
}
int main()
{
	cin >> n;
	vector<string> s(n);
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		insert(s[i]);
	}
	vector<string> z;
	for (int i = 0; i < n; i++)
	{
		if (ok(s[i]))
		{
			z.push_back(s[i]);
		}
	}
	cout << z.size() << endl;
	for (string i : z)
	{
		cout << i << endl;
	}
	return 0;
}
