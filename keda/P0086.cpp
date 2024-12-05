#include <bits/stdc++.h>
using namespace std;
void dfs(string pre, string in)
{
	if (in.size() > 0)
	{
		char ch = pre[0];
		int p = in.find(ch);
		dfs(pre.substr(1, p), in.substr(0, p));
		dfs(pre.substr(p + 1), in.substr(p + 1));
		cout << ch;
	}
}
int main()
{
	string pre, in;
	cin >> pre >> in;
	dfs(pre, in);
}