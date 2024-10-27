#include <bits/stdc++.h>
using namespace std;
const int m = 20;
int n, x;
int a[200020];
int s[1 << m | 1];
int t[1 << m | 1];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		s[a[i]]++;
		t[a[i]]++;
	}
	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < 1 << m; i++)
		{
			if (i >> j & 1)
			{
				s[i] += s[i ^ (1 << j)];
				t[i ^ (1 << j)] += t[i];
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << s[a[i]] << " " << t[a[i]] << " " << n - s[(1 << m) - 1 - a[i]] << endl;
	}
	return 0;
}