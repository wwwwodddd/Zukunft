#include <bits/stdc++.h>
using namespace std;
int n, a[100], b[100];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i];
	}
	for (int i = 0; i + 2 < n; i++)
	{
		if (a[i] == b[i] && a[i + 1] == b[i + 1] && a[i + 2] == b[i + 2])
		{
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}
