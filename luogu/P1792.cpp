#include <bits/stdc++.h>
using namespace std;
int L[200020], R[200020];
long long a[200020];
set<pair<long long, int> >s;
void del(int x)
{
	s.erase(make_pair(a[x], x));
	R[L[x]] = R[x];
	L[R[x]] = L[x];
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		s.insert(make_pair(a[i], i));
		L[(i + 1) % n] = i;
		R[i] = (i + 1) % n;
	}
	long long ans = 0;
	if (2 * m > n)
	{
		cout << "Error!" << endl;
	}
	else
	{
		for (int i = 0; i < m; i++)
		{
			int j = s.rbegin()->second;
			long long x = a[L[j]];
			long long y = a[j];
			long long z = a[R[j]];
			ans += y;
			del(L[j]);
			del(R[j]);
			s.erase(make_pair(a[j], j));
			a[j] = x + z - y;
			s.insert(make_pair(a[j], j));
		}
		cout << ans << endl;
	}
	return 0;
}