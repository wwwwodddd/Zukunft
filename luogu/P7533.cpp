#include <bits/stdc++.h>
using namespace std;
string s;
int n, z, a[256];
int main()
{
	a['A'] = 4;
	a['K'] = 3;
	a['Q'] = 2;
	a['J'] = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < s.size(); j++)
		{
			z += a[s[j]];
		}
	}
	cout << z << endl;
	return 0;
}
