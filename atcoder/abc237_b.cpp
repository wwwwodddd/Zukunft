#include <bits/stdc++.h>
using namespace std;
int n, m, a[100000];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i * m + j];
		}
	}
	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < n; i++)
		{
			cout << a[i * m + j] << " ";
		}
		cout << endl;
	}
	return 0;
}