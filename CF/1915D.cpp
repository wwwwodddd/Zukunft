#include <bits/stdc++.h>
using namespace std;
int t, n;
string s;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> s;
		vector<string> z;
		while (n > 0)
		{
			if (s[n - 1] == 'a' || s[n - 1] == 'e')
			{
				z.push_back(s.substr(n - 2, 2));
				n -= 2;
			}
			else
			{
				z.push_back(s.substr(n - 3, 3));
				n -= 3;
			}
		}
		for (int i = z.size() - 1; i > 0; i--)
		{
			cout << z[i] << ".";
		}
		cout << z[0] << endl;
	}
	return 0;
}