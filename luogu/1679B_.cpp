#include <bits/stdc++.h>
using namespace std;
int n, q, o, x, y, l;
map<int, int> a;
long long s;
int main()
{
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		s += a[i];
	}
	for (int i = 0; i < q; i++)
	{
		cin >> o;
		if (o == 1)
		{
			cin >> x >> y;
			if (a.find(x) == a.end())
			{
				a[x] = l;
			}
			s -= a[x];
			a[x] = y;
			s += a[x];
		}
		else
		{
			cin >> l;
			s = (long long)n * l;
			a.clear();
		}
		cout << s << endl;
	}
	return 0;
}
