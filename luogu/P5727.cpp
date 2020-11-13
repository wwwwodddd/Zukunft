#include <bits/stdc++.h>
using namespace std;
void dfs(int x)
{
	if (x == 1)
	{
		printf("1");
		return;
	}
	dfs(x & 1 ? 3 * x + 1 : x / 2);
	printf(" %d", x);
	return;
}
int main()
{
	int n;
	cin >> n;
	dfs(n);
	cout << endl;
	return 0;
}