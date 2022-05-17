#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> a[100020];
pair<int, int> b[100020];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first >> b[i].first;
		a[i].second = i;
		b[i].second = i;
	}
	sort(a, a + n);
	sort(b, b + n);
	if (a[0].second == b[0].second)
	{
		cout << min(a[0].first + b[0].first, min(max(a[0].first, b[1].first), max(a[1].first, b[0].first))) << endl;
	}
	else
	{
		cout << max(a[0].first, b[0].first) << endl;
	}
	return 0;
}
