#include <bits/stdc++.h>
using namespace std;
int n;
string s[100], t[100];
map<string, int> g;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i] >> t[i];
		g[s[i]]++;
		g[t[i]]++;
	}
	for (int i = 0; i < n; i++)
	{
		g[s[i]]--;
		g[t[i]]--;
		if (g[s[i]] > 0 && g[t[i]] > 0)
		{
			cout << "No" << endl;
			return 0;
		}
		g[s[i]]++;
		g[t[i]]++;
	}
	cout << "Yes" << endl;
	return 0;
}
