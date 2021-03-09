#include <bits/stdc++.h>
using namespace std;
int n, c[200], d[200];
pair<int, string> a[200];
int main()
{
	while (cin >> c[n] >> d[n] >> a[n].second)
	{
		n++;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i].first += abs(d[i] - d[j]) * c[j];
		}
	}
	sort(a, a + n);
	cout << a[0].second << ' ' << a[0].first << endl;
	return 0;
}