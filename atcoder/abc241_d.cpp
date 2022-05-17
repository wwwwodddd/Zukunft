#include <bits/stdc++.h>
using namespace std;
int q, o, k;
long long x;
multiset<long long> s;
int main()
{
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> o >> x;
		if (o == 1)
		{
			s.insert(x);
		}
		else
		{
			cin >> k;
			if (o == 2)
			{
				multiset<long long>::iterator it = s.upper_bound(x);
				long long z = *it;
				for (int i = 0; i < k; i++)
				{
					if (it != s.begin())
					{
						it--;
						z = *it;
					}
					else
					{
						z = -1;
					}
				}
				cout << z << endl;
			}
			else
			{
				multiset<long long>::iterator it = s.lower_bound(x);
				for (int i = 1; i < k; i++)
				{
					if (it != s.end())
					{
						it++;
					}
				}
				if (it == s.end())
				{
					cout << -1 << endl;
				}
				else
				{
					cout << *it << endl;
				}
			}
		}
	}
	return 0;
}
