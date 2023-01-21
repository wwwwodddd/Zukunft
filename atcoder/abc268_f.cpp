#include <bits/stdc++.h>
using namespace std;
long long z;
int n;
pair<int, int> a[200020];
string s[200020];
bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first * b.second == a.second * b.first)
	{
		return a < b;
	}
	return (long long)a.first * b.second > (long long)a.second * b.first;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		for (int j = 0; j < s[i].size(); j++)
		{
			if (s[i][j] == 'X')
			{
				a[i].first++;
			}
			else
			{
				int d = s[i][j] - '0';
				z += a[i].first * d;
				a[i].second += d;
			}
		}
	}
	sort(a, a + n, cmp);
	long long x = 0;
	for (int i = 0; i < n; i++)
	{
		z += a[i].second * x;
		x += a[i].first;
	}
	cout << z << endl;
	return 0;
}