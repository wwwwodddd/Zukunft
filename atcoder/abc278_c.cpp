#include <bits/stdc++.h>
using namespace std;
set<pair<int, int> > s;
int n, q, o, x, y;
int main()
{
	cin >> n >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> o >> x >> y;
		if (o == 1)
		{
			s.insert({x, y});
		}
		else if (o == 2)
		{
			s.erase({x, y});
		}
		else
		{
			cout << ((s.find({x, y}) != s.end() && s.find({y, x}) != s.end()) ? "Yes" : "No") << endl;
		}
	}
	return 0;
}
