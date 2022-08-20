#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a[100020];
int p[100020];
int y[100020];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> p[i] >> y[i];
		a[p[i]].push_back(y[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		sort(a[i].begin(), a[i].end());
	}
	for (int i = 0; i < m; i++)
	{
		int k = lower_bound(a[p[i]].begin(), a[p[i]].end(), y[i]) - a[p[i]].begin() + 1;
		cout << setw(6) << setfill('0') << p[i] << setw(6) << setfill('0') << k << endl;
		// printf("%06d%06d\n", p[i], k);
	}
	return 0;
}
