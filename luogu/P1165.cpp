#include <bits/stdc++.h>
using namespace std;
int n, x, y;
stack<int> s;
int main() {
	s.push(0);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (x == 0) {
			scanf("%d", &y);
			s.push(max(s.top(), y));
		} else if (x == 1) {
			s.pop();
		} else {
			printf("%d\n", s.top());
		}
	}
	return 0;
}