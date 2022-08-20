#include <bits/stdc++.h>
using namespace std;
char d[] = "22233344455566677778889999";
int n, z;
string s[1020], t;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		for (int j = 0; j < s[i].size(); j++)
		{
			s[i][j] = d[s[i][j] - 'a'];
		}
	}
	cin >> t;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == t)
		{
			z++;
		}
	}
	cout << z << endl;
	return 0;
}
