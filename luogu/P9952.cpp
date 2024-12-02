#include <bits/stdc++.h>
using namespace std;
char s[100020];
int n;
int main()
{
	scanf("%d", &n);
	scanf("%s", s);
	int prev = -1;
	vector<int> d;
	int first = -1;
	int last = -1;
	int cowcnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '1')
		{
			cowcnt++;
			if (first == -1)
			{
				first = i + 1;
			}
			last = n - i;
			if (prev != -1)
			{
				d.push_back(i - prev);
			}
			prev = i;
		}
	}
	int ans = 0;
	if (cowcnt == 0)
	{
		ans = n - 1;
	}
	else if (cowcnt == 1)
	{
		ans = max(ans, (first - 1) / 2);
		ans = max(ans, (last - 1) / 2);
		ans = max(ans, min(first - 1, last - 1));
	}
	else
	{
		sort(d.begin(), d.end());
		ans = max(ans, min(d[0], min(first - 1, last - 1)));
		ans = max(ans, min(min(d[0], first - 1), d.back() / 2));
		ans = max(ans, min(min(d[0], last - 1), d.back() / 2));
		if (cowcnt >= 2)
		{
			ans = max(ans, min(d[0], d.back() / 3));
		}
		if (cowcnt >= 3)
		{
			ans = max(ans, min(d[0], d[d.size() - 2] / 2));
		}
	}
	printf("%d\n", ans);
	return 0;
}