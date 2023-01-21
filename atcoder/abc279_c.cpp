#include <bits/stdc++.h>
using namespace std;
int n, m;
char c;
vector<string> s;
vector<string> t;
int main()
{
	cin >> n >> m;
	s.resize(m);
	t.resize(m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> c;
			s[j] += c;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> c;
			t[j] += c;
		}
	}
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	cout << (s == t ? "Yes" : "No") << endl;
	return 0;
}
