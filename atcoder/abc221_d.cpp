#include <bits/stdc++.h>
using namespace std;
int n, x, y, s;
pair<int, int> a[400020];
int z[200020];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		a[i + n] = make_pair(x, +1);
		a[i] = make_pair(x + y, -1);
	}
	sort(a, a + 2 * n);
	for (int i = 0; i + 1 < 2 * n; i++)
	{
		s += a[i].second;
		z[s] += a[i + 1].first - a[i].first; 
	}
	for (int i = 1; i <= n; i++)
	{
		cout << z[i] << " ";
	}
	cout << endl;
	return 0;
}
