#include <bits/stdc++.h>
using namespace std;
int n, x;
int s[200020];
vector<int> a[200020];
void dfs(int x)
{
	for (int i : a[x])
	{
		dfs(i);
		s[x] += s[i] + 1;
	}
}
int main()
{
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		cin >> x;
		a[x].push_back(i);
	}
	dfs(1);
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", s[i]);
	}
	return 0;
}