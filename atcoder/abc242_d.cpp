#include <bits/stdc++.h>
using namespace std;
string s;
int q;
long long t, k;
int main()
{
	cin >> s >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> t >> k;
		k--;
		long long p = 0;
		if (t < 60)
		{
			p = k >> t;
			k %= (1LL << t);
		}
		cout << char((s[p] - 'A' + (t + __builtin_popcountll(k))) % 3 + 'A') << endl;
	}
	return 0;
}