#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[100020];
bool v[100020];
int n, c, z = 1;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		if (a[i].second > i)
		{
			c++;
		}
		if (v[i])
		{
			c--;
		}
		v[a[i].second] = true;
		z = max(z, c);
	}
	cout << z << endl;
	return 0;
}