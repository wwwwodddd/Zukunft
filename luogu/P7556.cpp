#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[8];
int main()
{
//	cin >> n;
	n = 4;
	vector<int> v;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n + 1);
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			v.push_back(a[i] - a[j]); // a[i] >= a[j]
		}
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i; j < v.size(); j++)
		{
			for (int k = j; k < v.size(); k++)
			{
				// check v[i], v[j], v[k]
				int x = v[i], y = v[j], z = v[k];
				multiset<int> b = {x, y, z, x + y, x + z, y + z, x + y + z};
				int f = 1;
				for (int l = 1; l <= n; l++)
				{
					if (!b.count(a[l]))
					{
						f = 0;
						break;
					}
					else
					{
						b.erase(b.find(a[l]));
					}
				}
				if (f && x + y > z)
				{
					cout << x << " " << y << " " << z << endl;
				}
			}
		}
	}
	return 0;
}
