#include <bits/stdc++.h>
using namespace std;
int n;
long long k;
pair<int, int> a[200020];
int z[200020];
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a, a + n);
	for (int i = 0; i < k % n; i++)
	{
		z[a[i].second]++;
	}
	for (int i = 0; i < n; i++)
	{
		cout << k / n + z[i] << endl;
	}
	return 0;
}
