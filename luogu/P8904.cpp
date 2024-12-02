#include <bits/stdc++.h>
using namespace std;
int n, q, x, y, z;
long long h[2020];
set<int> l[2020];
set<int> r[2020];
bool can(int i, int j, int k)
{
	// i < j < k
	// whether (j, hj) <= (i, hi) (k, hk)
	return h[j] * (k - i) <= (h[i] * (k - j) + h[k] * (j - i));
}
void zuol(int x)
{
	z -= l[x].size();
	l[x].clear();
	for (int i = x - 1; i > 0; i--)
	{
		if (l[x].size() == 0 || can(i, *l[x].begin(), x))
		{
			l[x].insert(i);
		}
	}
	z += l[x].size();
}
void zuor(int x)
{
	z -= r[x].size();
	r[x].clear();
	for (int i = x + 1; i <= n; i++)
	{
		if (r[x].size() == 0 || can(x, *r[x].rbegin(), i))
		{
			r[x].insert(i);
		}
	}
	z += r[x].size();
}
void print()
{
	cout << "---" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << i << " " << l[i].size() << " " << r[i].size() << endl;
	}
	cout << "---" << endl;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> h[i];
	}
	for (int i = 1; i <= n; i++)
	{
		zuol(i);
		// zuor(i);
	}
	// print();
	// return 0;
	cin >> q;
	for (int qq = 0; qq < q; qq++)
	{
		cin >> x >> y;
		h[x] += y;
		z -= l[x].size();
		l[x].clear();
		vector<int> L;
		for (int i = x - 1; i > 0; i--)
		{
			if (L.size() == 0 || can(i, L.back(), x))
			{
				L.push_back(i);
				// x can see i
				// so i also can see x
				// auto u = r[i].insert(x);
				// if (u.second)
				// {
				// 	z++;
				// }
				// i   x   (some are blocked)
				// u.first + 1 ... u.first + ? are blocked
				// set<int>::iterator it = u.first;
				// it++;
				// while (it != r[i].end() && !can(i, x, *it))
				// {
				// 	r[i].erase(it++);
				// 	z--;
				// }
			}
		}
		l[x].insert(L.begin(), L.end());
		z += l[x].size();

		// z -= r[x].size();
		// r[x].clear();
		vector<int> R;
		for (int i = x + 1; i <= n; i++)
		{
			if (R.size() == 0 || can(x, R.back(), i))
			{
				R.push_back(i);
				auto u = l[i].insert(x);
				if (u.second)
				{
					z++;
				}
				// (some are blocked)   x   i
				// u.first - ? ... u.first - 1 are blocked
				set<int>::iterator it = u.first;
				while (true)
				{
					set<int>::iterator ti = it;
					if (ti == l[i].begin())
					{
						break;
					}
					ti--;
					if (!can(*ti, x, i))
					{
						l[i].erase(ti);
						z--;
					}
					else
					{
						break;
					}
				}
			}
		}
		// r[x].insert(R.begin(), R.end());
		// z += r[x].size();

		// print();
		// assert(z % 2 == 0);
		cout << z << endl;
	}
	return 0;
}