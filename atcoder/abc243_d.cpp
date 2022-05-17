#include <bits/stdc++.h>
using namespace std;
int n;
long long x;
char s[1000020];
vector<int> a;
int main()
{
	scanf("%d%lld%s", &n, &x, s);
	while (x > 0)
	{
		a.push_back(x & 1);
		x /= 2;
	}
	reverse(a.begin(), a.end());
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'U')
		{
			a.pop_back();
		}
		else if (s[i] == 'L')
		{
			a.push_back(0);
		}
		else
		{
			a.push_back(1);
		}
	}
	for (int i: a)
	{
		x = x * 2 + i;
	}
	printf("%lld\n", x);
	return 0;
}
