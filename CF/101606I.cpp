#include <bits/stdc++.h>
using namespace std;
int n, h;
int t[20];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}
	cin >> h;
	pair<int, int> best = make_pair(h, 0);
	for (int i = 0; i < n; i++) {
		best = min(best, make_pair(h % t[i], t[i]));
	}
	printf("%d\n", best.second);
	return 0;
}