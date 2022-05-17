#include <bits/stdc++.h>
using namespace std;
int n, m;
string a[100020];
string b;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0, j = 0; j < m; j++)
	{
		cin >> b;
		while (a[i] != b)
		{
			cout << "No" << endl;
			i++;
		}
		cout << "Yes" << endl;
		i++;
	}
	return 0;
}