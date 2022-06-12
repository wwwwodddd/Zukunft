#include<bits/stdc++.h>
using namespace std;
int n, m, mx, x;
int a[101];
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> x;
		if (a[x] == mx)
		{
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}
