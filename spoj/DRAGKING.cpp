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
		long long z = 0;
		for (int i = 0; i < s.size(); i++)
		{
			for (int j = 0; i - j >= 0 && i + j < s.size() && s[i - j] == s[i + j]; j++)
			{
				z += (2 * j + 1) * (2 * j + 1) * (2 * j + 1);
			}
			for (int j = 0; i - j >= 0 && i + j + 1 < s.size() && s[i - j] == s[i + j + 1]; j++)
			{
				z += (2 * j + 2) * (2 * j + 2) * (2 * j + 2);
			}
		}
		cout << z << endl;
	}
	return 0;
}