#include <bits/stdc++.h>
using namespace std;
int n, f, z;
string s[50], x;
int t[50];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i] >> t[i];
	}
	cin >> x;
	for (int i = 0; i < n; i++)
	{
		if (f)
		{
			z += t[i];
		}
		if (s[i] == x)
		{
			f = 1;
		}
	}
	cout << z << endl;
	return 0;
}
