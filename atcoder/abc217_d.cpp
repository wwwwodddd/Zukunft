#include <bits/stdc++.h>
using namespace std;
set<int> s;
int n, m, c, x;
int main()
{
	cin >> n >> m;
	s.insert(0);
	s.insert(n);
	for (int i = 0; i < m; i++)
	{
		cin >> c >> x;
		if (c == 1)
		{
			s.insert(x);
		}
		else
		{
			set<int>::iterator it = s.lower_bound(x);
			set<int>::iterator ti = it;
			ti--;
			cout << (*it - *ti) << endl;
		}
	}
	return 0;
}