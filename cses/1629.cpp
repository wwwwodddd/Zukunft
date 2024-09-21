#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> a[200020];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a + n);
	int c = 0, s = 0;
	for (int i = 0; i < n; i++)
	{
		if (s <= a[i].first)
		{
			c++;
			s = a[i].second;
		}
		else
		{
			s = min(s, a[i].second);
		}
	}
	cout << c << endl;
	return 0;
}