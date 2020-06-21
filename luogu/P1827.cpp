#include <bits/stdc++.h>
using namespace std;
void dfs(string in, string pre) {
	if (in.size() > 0) {
		char ch = pre[0];
		int p = in.find(ch);
		dfs(in.substr(0, p), pre.substr(1, p));
		dfs(in.substr(p + 1), pre.substr(p + 1));
		cout << ch;
	}
}
int main() {
	string in, pre;
	cin >> in >> pre;
	dfs(in, pre);
}