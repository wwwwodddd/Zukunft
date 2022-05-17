#include <bits/stdc++.h>
using namespace std;
int n;
char s[500020];
int main()
{
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'R')
		{
			cout << i << " ";
		}
	}
	for (int i = n; i >= 0; i--)
	{
		if (s[i] != 'R')
		{
			cout << i << " ";
		}
	}
	return 0;
}