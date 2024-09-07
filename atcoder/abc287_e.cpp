#include <bits/stdc++.h>
using namespace std;
int n;
pair<string, int> a[500020];
int z[500020];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a, a + n);
	for (int i = 1; i < n; i++)
	{
		int j = 0;
		while (j < a[i - 1].first.size() && j < a[i].first.size() && a[i - 1].first[j] == a[i].first[j])
		{
			j++;
		}
		z[a[i].second] = max(z[a[i].second], j);
		z[a[i - 1].second] = max(z[a[i - 1].second], j);
	}
	for(int i = 0; i < n; i++)
	{
		cout << z[i] << endl;
	}
	return 0;
}