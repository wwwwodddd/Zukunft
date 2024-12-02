#include <bits/stdc++.h>
using namespace std;
int n;
char s[300020];
void kao()
{
	scanf("%d%s", &n, s);
	int l = 0, r = n - 1;
	int lc = 0, rc = 0;
	vector<int> c;
	while (l < n && s[l] == '1')
	{
		lc++;
		l++;
	}
	while (0 <= r && s[r] == '1')
	{
		rc++;
		r--;
	}
	if (lc == n)
	{
		printf("%d\n", 1);
		return;
	}
	int cnt = 0;
	while (l <= r)
	{
		if (s[l] == '1')
		{
			cnt++;
		}
		else if (cnt > 0)
		{
			c.push_back(cnt);
			cnt = 0;
		}
		l++;
	}
	int t = n;
	if (lc > 0)
	{
		t = min(t, lc - 1);
	}
	if (rc > 0)
	{
		t = min(t, rc - 1);
	}
	for (int i : c)
	{
		t = min(t, (i - 1) / 2);
	}
	int s = 0;
	if (lc > 0)
	{
		s += (lc + t * 2) / (t * 2 + 1);
	}
	if (rc > 0)
	{
		s += (rc + t * 2) / (t * 2 + 1);
	}
	for (int i : c)
	{
		s += (i + t * 2) / (t * 2 + 1);
	}
	printf("%d\n", s);
}
int main()
{
	kao();
	return 0;
}