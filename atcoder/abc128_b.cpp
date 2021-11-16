#include <bits/stdc++.h>
using namespace std;
int n;
pair<pair<string, int>, int> a[120];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first.first >> a[i].first.second;
		a[i].first.second *= -1;
		a[i].second = i + 1;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		cout << a[i].second << endl;
	}
	return 0;
}
