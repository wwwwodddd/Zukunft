#include <bits/stdc++.h>
using namespace std;
string s;
int a[500020];
int b[500020];
long long z;
int main()
{
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '<')
		{
			a[i + 1] = a[i] + 1;
		}
	}
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (s[i] == '>')
		{
			b[i] = b[i + 1] + 1;
		}
	}
	for (int i = 0; i <= s.size(); i++)
	{
		z += max(a[i], b[i]);
	}
	cout << z << endl;
	return 0;
}
