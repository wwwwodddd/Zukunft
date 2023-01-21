#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[500020];
vector<int> b;
int n, m;
int mx[4000020];
int ad[4000020];
bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.second - a.first < b.second - b.first;
}
int Q(int x)
{
	return lower_bound(b.begin(), b.end(), x) - b.begin();
}
void add(int x, int add)
{
	mx[x] += add;
	ad[x] += add;
}
void push(int x)
{
	add(x * 2, ad[x]);
	add(x * 2 + 1, ad[x]);
	ad[x] = 0;
}
void change(int x, int l, int r, int L, int R, int v)
{
	if (r < L || R < l)
	{
		return;
	}
	if (L <= l && r <= R)
	{
		add(x, v);
		return;
	}
	push(x);
	int mid = (l + r) / 2;
	change(x * 2, l, mid, L, R, v);
	change(x * 2 + 1, mid + 1, r, L, R, v);
	mx[x] = max(mx[x * 2], mx[x * 2 + 1]);
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &a[i].first, &a[i].second);
		b.push_back(a[i].first);
		b.push_back(a[i].second);
	}
	sort(a, a + n, cmp);
	sort(b.begin(), b.end());
	b.resize(unique(b.begin(), b.end()) - b.begin());
	int z = 2e9, j = 0, i = 0;
	while (true)
	{
		if (mx[1] >= m)
		{
			z = min(z, (a[i - 1].second - a[i - 1].first) - (a[j].second - a[j].first));
			change(1, 0, b.size() - 1, Q(a[j].first), Q(a[j].second), -1);
			j++;
		}
		else
		{
			if (i == n)
			{
				break;
			}
			change(1, 0, b.size() - 1, Q(a[i].first), Q(a[i].second), +1);
			i++;
		}
	}
	if (z == 2e9)
	{
		z = -1;
	}
	printf("%d\n", z);
	return 0;
}
