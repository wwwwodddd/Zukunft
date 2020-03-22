#include <bits/stdc++.h>
using namespace std;
int n, x, y;
stack<int> s;
int main() {
	scanf("%d", &n);
	s.push(0);
	int ans = n;
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &x, &y);
		while (y < s.top()) {
			s.pop();
		}
		if (y > s.top()) {
			s.push(y);
		} else {
			ans--;
		}
	}
	printf("%d\n", ans);
	return 0;
}