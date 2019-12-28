#include <bits/stdc++.h>
using namespace std;
string s[8] = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
string a[7], b[7], c, d, e, f;
int n;
bool good(string a, string b)
{
	for (int i = 0; i < 7; i++)
	{
		if (s[i] == a && s[i + 1] == b)
		{
			return true;
		}
		if (s[i] == b && s[i + 1] == a)
		{
			return true;
		}
	}
	return false;
}
bool ok()
{
	for (int i = 0; i < n; i++)
	{
		if (!good(a[i], b[i]))
		{
			return false;
		}
	}
	return true;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> c >> d >> e >> f >> b[i];
	}
	sort(s, s + 8);
	do
	{
		if (ok())
		{
			for (int i = 0; i < 8; i++)
			{
				cout << s[i] << endl;
			}
			break;
		}
	}
	while(next_permutation(s, s + 8));
	return 0;
}