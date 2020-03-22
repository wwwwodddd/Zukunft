#include <bits/stdc++.h>
using namespace std;
void dfs(string in, string post) {
	if (in.size() > 0) {
		char ch = post[post.size() - 1];
		cout << ch;
		int p = in.find(ch);
		dfs(in.substr(0, p), post.substr(0, p));
		dfs(in.substr(p + 1), post.substr(p, post.size() - 1 - p));
	}
}
int main() {
	string in, post;
	cin >> in >> post;
	dfs(in, post);
}