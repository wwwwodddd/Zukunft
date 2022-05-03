#include <bits/stdc++.h>
using namespace std;
int t, n;
string s;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		long long z = 0;
		int a[26] = {};
		int b[26] = {};
		int c[26][26] = {};
		for (int i = 0; i < n; i++)
		{
			cin >> s;
			z += a[s[0]] + b[s[1]] - c[s[0]][s[1]];
			a[s[0]]++;
			b[s[1]]++;
			c[s[0]][s[1]]++;
		}
		cout << z << endl;
	}
}
