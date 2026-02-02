#include <bits/stdc++.h>
using namespace std;
long long c[70][70];
int a[10];
string s;
long long calc()
{
	long long f = 1, s = 0;
	for (int i = 0; i < 10; i++)
	{
		s += a[i];
		f *= c[s][a[i]];
	}
	return f;
}
int main()
{
	for (int i = 0; i < 62; i++)
	{
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
	}
	cin >> s;
	for (auto i : s)
	{
		a[i - '0']++;
	}
	long long z = 0;
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 0; j < s[i] - '0'; j++)
		{
			if (a[j] > 0)
			{
				a[j]--;
				z += calc();
				a[j]++;
			}
		}
		a[s[i] - '0']--;
	}
	cout << z << endl;
	return 0;
}