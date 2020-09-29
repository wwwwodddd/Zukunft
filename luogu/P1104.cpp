#include <bits/stdc++.h>
using namespace std;
int n, y, m, d;
pair<int, string> a[100];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].second >> y >> m >> d;
		a[i].first = ((y * 100 + m) * 100 + d) * 100 - i;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		cout << a[i].second << endl;
	}
	return 0;
}