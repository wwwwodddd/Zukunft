#include <bits/stdc++.h>
using namespace std;
int n, q, o, x;
set<int> s;
int main()
{
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		s.insert(i);
	}
	for (int i = 0; i < q; i++)
	{
		cin >> o;
		if (o == 2)
		{
			cin >> x;
			s.erase(x);
		}
		else if (o == 3)
		{
			cout << *s.begin() << endl;
		}
	}
	return 0;
}