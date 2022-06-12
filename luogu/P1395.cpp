#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a[50020]; // 存树
int s[50020]; // s[x]为x子树的大小
int f[50020]; 
void dfs(int x, int y) {
	s[x] = 1;
	// x子树内部的点到x距离之和。
	for (int i = 0; i < a[x].size(); i++) {
		if (a[x][i] != y) {
			dfs(a[x][i], x);
			s[x] += s[a[x][i]]; // 递归计算x子树的大小 
			f[x] += f[a[x][i]] + s[a[x][i]];
			// x子树内部的点到x距离之和。
			// a[x][i]子树内部每个点，到x的距离比到a[x][i]的距离多1
			// 所以贡献是 a[x][i]子树内部每个点到a[x][i] 加上 s[a[x][i]] 
		}
	}
}
void sfd(int x, int y) {
	for (int i = 0; i < a[x].size(); i++) {
		if (a[x][i] != y) {
			// f[x] x的答案
			// -(f[a[x][i]] + s[a[x][i]])  删去a[x][i]子树部分
			// (n - s[a[x][i]]) 为a[x][i]父亲方向的size
			// x的答案，减去a[x][i]子树部分的影响，加上a[x][i]父亲方向的size
			f[a[x][i]] += f[x] - (f[a[x][i]] + s[a[x][i]]) + (n - s[a[x][i]]);
			// 现在f[a[x][i]]为所有点到a[x][i]的距离之和 
			sfd(a[x][i], x);
			// 递归处理每个孩子 
		}
	}
}
int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		a[y].push_back(x);
		a[x].push_back(y);
	}
	dfs(1, 0);
	// 做完dfs，f[1]就是所有点到1的距离了 
	// 但是对于其他的i，f[i]只考虑了i子树内到i的情况
	// 没有考虑i的父亲节点方向到i的情况 
	// sfd处理每个点父亲节点方向到i的情况 
	sfd(1, 0);
	int ans = 1;
	// ans初始化为1
	for (int i = 1; i <= n; i++) {
		if (f[ans] > f[i]) {
			// 如果i比ans更好，那么更新 
			ans = i;
		}
	}
	cout << ans << ' ' << f[ans] << endl;
	return 0;
}
