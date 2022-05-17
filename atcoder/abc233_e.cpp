#include <bits/stdc++.h>
using namespace std;
string s;
int n, a[500020];
int main()
{
	cin >> s;
	reverse(s.begin(), s.end());
	n = s.size();
	for (int i = 0; i < n; i++)
	{
		a[i] = s[i] - '0';
	}
	for (int i = n - 1; i >= 0; i--)
	{
		a[i] += a[i + 1];
	}
	n += 1;
	for (int i = 0; i < n; i++)
	{
		a[i + 1] += a[i] / 10;
		a[i] %= 10;
	}
	while (a[n - 1] == 0)
	{
		n--;
	}
	for (int i = n - 1; i >= 0; i--)
	{
		cout << a[i];
	}
	cout << endl;
	return 0;
}
