#include <bits/stdc++.h>
using namespace std;
int l[1000020];
int r[1000020];
int n;
int dfs(int x)
{
	return x ? max(dfs(l[x]), dfs(r[x])) + 1 : 0;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> l[i] >> r[i];
	}
	cout << dfs(1) << endl;
	return 0;
}