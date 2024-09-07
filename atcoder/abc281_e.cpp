#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a[200020];
multiset<int> up, dn;
long long ups, dns;
int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (up.size() == 0 || a[i] < *up.begin())
		{
			dn.insert(a[i]);
			dns += a[i];
		}
		else
		{
			up.insert(a[i]);
			ups += a[i];
		}

		if (i - m >= 0)
		{
			if (dn.find(a[i - m]) != dn.end())
			{
				dn.erase(dn.find(a[i - m]));
				dns -= a[i - m];
			}
			else
			{
				up.erase(up.find(a[i - m]));
				ups -= a[i - m];
			}
		}
		if (i >= m - 1)
		{
			while (dn.size() > k)
			{
				int x = *--dn.end();
				dn.erase(dn.find(x));
				dns -= x;
				up.insert(x);
				ups += x;
			}
			while (dn.size() < k)
			{
				int x = *up.begin();
				up.erase(up.find(x));
				ups -= x;
				dn.insert(x);
				dns += x;
			}
			cout << dns << " ";
		}
	}
	return 0;
}
