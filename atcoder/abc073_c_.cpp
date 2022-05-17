#include <bits/stdc++.h>
using namespace std;
int n, ss;
int a[100020];
int s[100020];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		if (a[i] == s[ss])
		{
			ss--;
		}
		else
		{
			s[++ss] = a[i];
		}
	}
	cout << ss << endl;
	return 0;
}
