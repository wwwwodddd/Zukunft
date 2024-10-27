#include <bits/stdc++.h>
using namespace std;
stack<pair<int, int> > s;
int n, x;
int b[1020][1020];
long long z;
void push(int x)
{
	long long t = 0;
	while (s.size() && s.top().first >= x)
	{
		t += s.top().second;
		z = max(z, t * s.top().first);
		s.pop();
	}
	s.push(make_pair(x, t + 1));
}
int main()
{
	scanf("%d", &n);
	for (int j = 0; j < n; j++)
	{
		scanf("%d", &x);
		push(x);
	}
	push(0);
	printf("%lld\n", z);
	return 0;
}