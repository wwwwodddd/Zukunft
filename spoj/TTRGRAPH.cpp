#include <bits/stdc++.h>
using namespace std;
const int N = 900;
int n, m, x, y;
vector<int> a[N];
bitset<N> b[N];
int main()
{
	cin >> n;
	for (int i = -1; i < n; i++)
	{
		string s;
		getline(cin, s);
		stringstream ss(s);
		while (ss >> x)
		{
			if (i < x)
			{
				a[i].push_back(x);
				b[i][x] = 1;
			}
		}
	}
	long long z = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j: a[i])
		{
			bitset<N> s = (b[i] & b[j]);
			for (int k: a[j])
			{
				if (b[i][k])
				{
					z += (s & b[k]).count();
				}
			}
		}
	}
	printf("%lld\n", z);
	return 0;
}