#include <bits/stdc++.h>
using namespace std;
int n, s, c;
pair<int, int> a[400020];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i + n].first;
		a[i].second = 1;
		a[i + n].second = -1;
	}
	sort(a, a + 2 * n);
	for (int i = 0; i < 2 * n; i++)
	{
		c += a[i].second;
		s = max(s, c);
	}
	cout << s << endl;
	return 0;
}