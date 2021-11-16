#include <bits/stdc++.h>
using namespace std;
int n, s;
string a[1020];
int b[1020];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i];
		s += b[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (2 * b[i] > s)
		{
			cout << a[i] << endl;
			return 0;
		}
	}
	cout << "atcoder" << endl;
	return 0;
}
