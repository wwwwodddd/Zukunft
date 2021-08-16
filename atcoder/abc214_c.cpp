#include <bits/stdc++.h>
using namespace std;
int n;
int s[200020];
int t[200020];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> t[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (t[(i + 1) % n] > t[i] + s[i])
		{
			t[(i + 1) % n] = t[i] + s[i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (t[(i + 1) % n] > t[i] + s[i])
		{
			t[(i + 1) % n] = t[i] + s[i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << t[i] << endl;
	}
	return 0;
}
