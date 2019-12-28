#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[100020];
pair<int, int> b[100020];
pair<int, int> w[100020];
int n, l;
long long calc()
{
	long long re = 0;
	long long cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (b[i].second == -1)
		{
			cnt++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (b[i].second == -1)
		{
			cnt--;
		}
		else
		{
			re += cnt;
		}
	}
	return re;
}
int main()
{
	int sum = 0, cur = 0;
	scanf("%d%d", &n, &l);
	int L = 0;
	int R = n;
	for (int i = 0; i < n; i++)
	{
		int d;
		scanf("%d%d%d", &w[i].second, &w[i].first, &d);
		b[i].first = w[i].first;
		b[i].second = d;
		sum += w[i].second;
		if (d == -1)
		{
			a[i] = make_pair(w[i].first, 0); // left;
		}
		else
		{
			a[i] = make_pair(l - w[i].first, 1); // right;
		}
	}
	sort(w, w + n);
	sort(a, a + n);
	int tim = -1;
	for (int i = 0; i < n; i++)
	{
		if (a[i].second == 0)
		{
			cur += w[L++].second;
		}
		else
		{
			cur += w[--R].second;
		}
		if (cur * 2 >= sum)
		{
			tim = a[i].first;
			break;
		}
	}
	sort(b, b + n);
	long long ans = calc();
	for (int i = 0; i < n; i++)
	{
		b[i].first += b[i].second * tim;
	}
	sort(b, b + n);
	ans -= calc();
	printf("%lld\n", ans);
	return 0;
}