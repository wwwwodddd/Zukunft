#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, string> a[520];
pair<int, string> b[520];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].second;
		for (int j = 0; j < 5; j++)
		{
			int x;
			cin >> x;
			a[i].first -= x;
		}
		b[i] = a[i];
	}
	sort(b, b + n);
	for (int i = 0; i < n; i++)
	{
		pair<int, string> u = make_pair(a[i].first - 500, a[i].second);
		pair<int, string> v = make_pair(a[i].first + 500, a[i].second);
//		int x = 1, y = 0;
//		for (int j = 0; j < n; j++)
//		{
//			if (a[j] < u)
//			{
//				x++;
//			}
//			if (a[j] < v)
//			{
//				y++;
//			}
//		}
//		cout << x << " " << y << endl;
		int f = lower_bound(b, b + n, u) - b + 1;
		int g = lower_bound(b, b + n, v) - b;
		cout << f << " " << g << endl;
	}
	return 0;
}
