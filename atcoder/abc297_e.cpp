#include <bits/stdc++.h>
using namespace std;
int n, k;
long long a[10];
set<long long> s;
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	s.insert(0);
	for (int j = 0; j < k; j++)
	{
		for (int i = 0; i < n; i++)
		{
			s.insert(*s.begin() + a[i]);
		}
		s.erase(s.begin());
	}
	cout << *s.begin() << endl;
	return 0;
}