#include <bits/stdc++.h>
using namespace std;
int n, m;
set<vector<int> > s;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		vector<int> a(m);
		for (int i = 0; i < m; i++)
		{
			cin >> a[i];
		}
		s.insert(a);
	}
	cout << s.size() << endl;
	return 0;
}