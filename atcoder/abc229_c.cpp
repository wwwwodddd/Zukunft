#include <bits/stdc++.h>
using namespace std;
int n, w;
pair<int, int> a[300020];
long long z;
int main()
{
	cin >> n >> w;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a + n);
	for (int i = n - 1; i >= 0; i--)
	{
		long long t = min(w, a[i].second);
		w -= t;
		z += t * a[i].first;
	}
	cout << z << endl;
	return 0;
}
