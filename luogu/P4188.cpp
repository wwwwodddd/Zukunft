#include <bits/stdc++.h>
using namespace std;
int n, c, s, l, z;
pair<int, int> a[200020];
int b[200020];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i + n].first;
		a[i].second = i + 1;
		a[i + n].second = -i - 1;
	}
	sort(a, a + 2 * n);
	for (int i = 0; i < 2 * n; i++)
	{
		if (c > 0)
		{
			z += a[i].first - l;
		}
		if (c == 1)
		{
			b[s] += a[i].first - l;
		}
		if (a[i].second > 0)
		{
			c++;
		}
		else
		{
			c--;
		}
		s += a[i].second;
		l = a[i].first;
	}
	cout << z - *min_element(b + 1, b + 1 + n) << endl;
	return 0;
}