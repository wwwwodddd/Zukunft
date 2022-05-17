#include <bits/stdc++.h>
using namespace std;
string s, t;
int main()
{
	cin >> s >> t;
	int z = t.size();
	for (int i = 0; i <= s.size() - t.size(); i++)
	{
		int c = 0;
		for (int j = 0; j < t.size(); j++)
		{
			c += t[j] != s[i + j];
		}
		z = min(z, c);
	}
	cout << z << endl;
	return 0;
}
