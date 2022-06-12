#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200020];
vector<int> b[200020];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		b[i % m].push_back(a[i]);
	}
	for (int i = 0; i < m; i++)
	{
		sort(b[i].begin(), b[i].end());
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		if (b[i % m][i / m] != a[i])
		{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}
