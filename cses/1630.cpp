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
	long long s = 0, z = 0;
	for (int i = 0; i < n; i++)
	{
		s += a[i].first;
		z += a[i].second - s;
	}
	cout << z << endl;
	return 0;
}