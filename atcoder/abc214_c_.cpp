#include <bits/stdc++.h>
using namespace std;
int n;
int s[200020];
int t[200020];
set<pair<int, int> > a;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> t[i];
		a.insert(make_pair(t[i], i));
	}
	while (a.size() > 0)
	{
		int i = a.begin()->second;
		a.erase(a.begin());
		if (t[(i + 1) % n] > t[i] + s[i])
		{
			a.erase(make_pair(t[(i + 1) % n], (i + 1) % n));
			t[(i + 1) % n] = t[i] + s[i];
			a.insert(make_pair(t[(i + 1) % n], (i + 1) % n));
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << t[i] << endl;
	}
	return 0;
}
