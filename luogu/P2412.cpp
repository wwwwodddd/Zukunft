#include <bits/stdc++.h>
using namespace std;
int n, m;
string s[200020];
bool cmp(const string &a, const string &b)
{
	for (int i = 0; i < a.size() && i < b.size(); i++)
	{
		if (tolower(a[i]) != tolower(b[i]))
		{
			return tolower(a[i]) < tolower(b[i]);
		}
	}
	return a.size() < b.size();
}
string maxstr(const string &a, const string &b)
{
	if (cmp(a, b))
	{
		return b;
	}
	else
	{
		return a;
	}
}
void build(int x, int L, int R)
{
	if (L == R)
	{
		cin >> s[x];
		return;
	}
	int M = (L + R) / 2;
	build(x * 2, L, M);
	build(x * 2 + 1, M + 1, R);
	s[x] = maxstr(s[x * 2], s[x * 2 + 1]);
}
string query(int x, int L, int R, int l, int r)
{
	if (R < l || r < L)
	{
		return "";
	}
	if (l <= L && R <= r)
	{
		return s[x];
	}
	int M = (L + R) / 2;
	return maxstr(query(x * 2, L, M, l, r), query(x * 2 + 1, M + 1, R, l, r));
}

int main()
{
	cin >> n >> m;
	build(1, 1, n);
	for (int i = 0; i < m; i++)
	{
		int l, r;
		cin >> l >> r;
		cout << query(1, 1, n, l, r) << endl;
	}
	return 0;
}
