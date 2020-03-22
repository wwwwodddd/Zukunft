#include <bits/stdc++.h>
using namespace std;
int n;
char L[256];
char R[256];
void dfs(char c) {
	cout << c;
	if (L[c] != 0 && L[c] != '*') {
		dfs(L[c]);
	}
	if (R[c] != 0 && R[c] != '*') {
		dfs(R[c]);
	}
}
int main() {
	cin >> n;
	char x, y, z, rt;
	for (int i = 0; i < n; i++) {
		cin >> x;
		cin >> L[x];
		cin >> R[x];
		if (i == 0) {
			rt = x;
		}
	}
	dfs(rt);
	return 0;
}
