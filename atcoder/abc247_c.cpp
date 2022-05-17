#include <bits/stdc++.h>
using namespace std;
void dfs(int x)
{
	if (x == 0)
	{
		return;
	}
	dfs(x - 1);
	cout << x << " ";
	dfs(x - 1);
}
int n;
int main()
{
	cin >> n;
	dfs(n);
	return 0;
}
