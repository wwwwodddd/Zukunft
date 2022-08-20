#include <bits/stdc++.h>
using namespace std;
string s, t = "atcoder";
int a[10], n = t.size(), z;
int main()
{
	cin >> s;
	for (int i = 0; i < n; i++)
	{
		a[i] = t.find(s[i]);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j] > a[i])
			{
				z++;
			}
		}
	}
	cout << z << endl;
	return 0;
}
