#include <bits/stdc++.h>
using namespace std;
int t;
string s;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> s;
		int z = 0;
		for (char c : s)
		{
			z = (z * 10 + c - '0') % 11;
		}
		cout << (z ? "No" : "Yes") << endl;
	}
	return 0;
}