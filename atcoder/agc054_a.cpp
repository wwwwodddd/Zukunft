#include <bits/stdc++.h>
using namespace std;
int n, z = -1;
string s;
int main()
{
	cin >> n >> s;
	if (s[0] != s[n - 1])
	{
		z = 1;
	}
	else for (int i = 0; i < n; i++)
	{
		if (s[0] != s[i] && s[i + 1] != s[n - 1])
		{
			z = 2;
		}
	}
	cout << z << endl;
	return 0;
}
