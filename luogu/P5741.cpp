#include <bits/stdc++.h>
using namespace std;
int n;
string s[1020];
int a[1020];
int b[1020];
int c[1020];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i] >> a[i] >> b[i] >> c[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (abs(a[i] - a[j]) <= 5 && abs(b[i] - b[j]) <= 5 && abs(c[i] - c[j]) <= 5 && abs(a[i] + b[i] + c[i] - a[j] - b[j] - c[j]) <= 10)
			{
				cout << s[i] << ' ' << s[j] << endl;
			}
		}
	}
	return 0;
}