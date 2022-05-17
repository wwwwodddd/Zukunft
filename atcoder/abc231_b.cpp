#include <bits/stdc++.h>
using namespace std;
int n;
string s[100];
int zc;
string zs;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	for (int i = 0; i < n; i++)
	{
		int c = 0;
		for (int j = 0; j < n; j++)
		{
			if (s[i] == s[j])
			{
				c++;
			}
		}
		if (zc < c)
		{
			zc = c;
			zs = s[i];
		}
	}
	cout << zs << endl;
	return 0;
}
