#include <bits/stdc++.h>
using namespace std;
int n, z;
map<string, int> g;
string s;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (i < 2 * g[s])
		{
			z++;
		}
		g[s]++;
	}
	cout << z << endl;
	return 0;
}