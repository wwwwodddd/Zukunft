#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> a[200020];
vector<pair<int, int> > z;
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
		if (z.size() == 0 || z.back().second < a[i].first)
		{
			z.push_back(a[i]);
		}
		else
		{
			z.back().second = max(z.back().second, a[i].second);
		}
	}
	for (auto i : z)
	{
		cout << i.first << " " << i.second << endl;
	}
	return 0;
}
