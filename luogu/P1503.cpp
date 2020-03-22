#include <bits/stdc++.h>
using namespace std;
stack<int> a;
char o[2];
set<int> s;
int n, m, x;
int main() {
	scanf("%d%d", &n, &m);
	s.insert(0);
	s.insert(n+1);
	for (int i = 0; i < m; i++) {
		scanf("%s", o);
		if (o[0] == 'D') {
			scanf("%d", &x);
			s.insert(x);
			a.push(x);
		} else if (o[0] == 'R') {
			s.erase(a.top());
			a.pop();
		} else if (o[0] == 'Q') {
			scanf("%d", &x);
			if (s.find(x) != s.end()) {
				printf("0\n");
			} else {
				set<int>::iterator it;
				it = s.lower_bound(x);
//				it = s.upper_bound(x);
				set<int>::iterator ti=it;
				ti--;
				printf("%d\n", *it - *ti - 1);
			}
		}
	}
	return 0;
}