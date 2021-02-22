#include <bits/stdc++.h>
using namespace std;
int n;
int a[3000020];
int f[3000020];
stack<int> s;
int main()
{
	scanf("%d",&n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		while (s.size() > 0 && a[i] > a[s.top()])
		{
			f[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d%c", f[i], i == n ? '\n' : ' ');
	}
	return 0;
}