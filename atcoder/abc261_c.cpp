#include <bits/stdc++.h>
using namespace std;
int n;
string s;
map<string, int> g;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (g[s] == 0)
		{
			cout << s << endl;
		}
		else
		{
			cout << s << "(" << g[s] << ")" << endl;
		}
		g[s]++;
	}
	return 0;
}
