#include <bits/stdc++.h>
using namespace std;
int n, l, z;
pair<int, int> a[500020];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		if (l < a[i].first)
		{
			z++;
			l = a[i].second;
		}
		else if (l > a[i].second)
		{
			l = a[i].second;
		}
	}
	cout << z << endl;
	return 0;
}
