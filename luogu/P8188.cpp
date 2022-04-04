#include <bits/stdc++.h>
using namespace std;
int t, m, n, k;
set<pair<int, int> > passed;
set<pair<int, int> > i2ai, ai2i;
int a[100020];
int c[100020];
int fp, ap;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> m >> n >> k;
		memset(c, 0, sizeof c);
		passed.clear();
		i2ai.clear();
		ai2i.clear();
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			c[a[i]]++;
		}
		fp = 1;
		ap = 1;
		while (true)
		{
			while (i2ai.size() < k && (passed.size() > 0 || ap <= n))
			{
				if (ap <= n)
				{
					i2ai.insert(make_pair(ap, a[ap]));
					ai2i.insert(make_pair(a[ap], ap));
					ap++;
				}
				else
				{
					pair<int, int> u = *--passed.end();
					passed.erase(--passed.end());
					i2ai.insert(u);
					ai2i.insert(make_pair(u.second, u.first));
				}
			}
			while (fp + k - 1 < m && c[fp] == 0)
			{
				fp++;
			}
			bool changed = false;
			while (true)
			{
				set<pair<int, int> >::iterator it = ai2i.lower_bound(make_pair(fp, 0));
				if (it != ai2i.end() && it->first <= fp + k - 1)
				{
					c[it->first]--;
					i2ai.erase(make_pair(it->second, it->first));
					ai2i.erase(it);
					changed = true;
				}
				else
				{
					break;
				}
			}
			if (!changed)
			{
				if (ap <= n)
				{
					i2ai.insert(make_pair(ap, a[ap]));
					ai2i.insert(make_pair(a[ap], ap));
					ap++;
					if (i2ai.size() > k)
					{
						passed.insert(*i2ai.begin());
						ai2i.erase(make_pair(i2ai.begin()->second, i2ai.begin()->first));
						i2ai.erase(i2ai.begin());
					}
				}
				else
				{
					break;
				}
			}
		}
		cout << (ai2i.size() == 0 ? "YES" : "NO") << endl;
	}
	return 0;
}