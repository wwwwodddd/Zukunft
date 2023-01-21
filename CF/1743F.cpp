#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int n, z;
int l[300020];
int r[300020];
set<int> s;
long long p2[300020];
long long p3[300020];
int main()
{
	for (int i = p2[0] = p3[0] = 1; i < 300020; i++)
	{
		p2[i] = p2[i - 1] * 2 % p;
		p3[i] = p3[i - 1] * 3 % p;
	}
	for (int i = 0; i < 300010; i++)
	{
		s.insert(i);
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> l[i] >> r[i];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		for (auto j = s.lower_bound(l[i]); *j <= r[i];)
		{
			if (i == 0)
			{
				z = (z + p2[n - 1]) % p;
			}
			else
			{
				z = (z + (long long)p3[i - 1] * p2[n - i]) % p;
			}
			s.erase(j++);
		}
	}
	cout << z << endl;
	return 0;
}