#include <bits/stdc++.h>
using namespace std;
multiset<long long> s;
int q, o, x;
long long add;
int main()
{
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> o;
		if (o == 1)
		{
			cin >> x;
			s.insert(x - add);
		}
		else if (o == 2)
		{
			cin >> x;
			add += x;
		}
		else
		{
			cout << *s.begin() + add << endl;
			s.erase(s.begin());
		}
	}
	return 0;
}
