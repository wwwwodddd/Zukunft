#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<int, int> > a, b;
vector<pair<ll, ll> > A[42], B[42];
pair<ll, ll> c[1048577];
int n, xg, yg;
void gen(vector<pair<int, int> > &a, vector<pair<ll, ll> > A[])
{
	memset(c, 0, sizeof c);
	for (int i = 0; i < a.size(); i++)
	{
		c[1 << i] = a[i];
	}
	for (int i = 1; i < 1 << a.size(); i++)
	{
		int lb = i & -i;
		int j = i - lb;
		c[i] = make_pair(c[lb].first + c[j].first, c[lb].second + c[j].second);
	}
	for (int i = 0; i < 1 << a.size(); i++)
	{
		A[__builtin_popcount(i)].push_back(c[i]);
	}
}
int main()
{
	cin >> n >> xg >> yg;
	for (int i = 0; i < n; i++)
	{
		pair<int, int> p;
		cin >> p.first >> p.second;
		if (i & 1)
		{
			b.push_back(p);
		}
		else
		{
			a.push_back(p);
		}
	}
	gen(a, A);
	gen(b, B);
	for (int i = 0; i <= n; i++)
	{
		sort(A[i].begin(), A[i].end());
		sort(B[i].begin(), B[i].end());
	}
	for (int k = 1; k <= n; k++)
	{
		long long z = 0;
		for (int i = 0; i <= k; i++)
		{
			int j = k - i;
			if (A[i].size() == 0 || B[j].size() == 0)
			{
				continue;
			}
			for (pair<ll, ll> p: A[i])
			{
				pair<ll, ll> q = make_pair(xg - p.first, yg - p.second);
				z += upper_bound(B[j].begin(), B[j].end(), q) - lower_bound(B[j].begin(), B[j].end(), q);
			}
		}
		cout << z << endl;
	}
	return 0;
}