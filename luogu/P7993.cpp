#include <bits/stdc++.h>
using namespace std;
int n;
char s[500020];
vector<pair<char, int> > a;
long long z;
int main()
{
	scanf("%d%s", &n, s);
	char c = s[0];
	int t = 1;
	for (int i = 1; i < n; i++)
	{
		if (s[i] == c)
		{
			t++;
		}
		else
		{
			a.push_back(make_pair(c, t));
			c = s[i];
			t = 1;
		}
	}
	a.push_back(make_pair(c, t));
	for (unsigned i = 0; i < a.size(); i++)
	{
		if (i > 0 && i + 1 < a.size() && a[i].second == 1)
		{
			z += (long long)a[i - 1].second * a[i + 1].second;
		}
		if (i > 0)
		{
			z += a[i - 1].second - 1;
		}
		if (i + 1 < a.size())
		{
			z += a[i + 1].second - 1;
		}
	}
	printf("%lld\n", z);
	return 0;
}