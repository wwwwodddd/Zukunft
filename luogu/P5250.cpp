#include <bits/stdc++.h>
using namespace std;
set<int> s;
int n, o, x;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> o >> x;
		if (o == 1) {
			if (!s.insert(x).second) {
				printf("Already Exist\n");
			}
		} else {
			if (s.size()) {
				set<int>::iterator it;
				it = s.lower_bound(x);
				set<int>::iterator ti=it;
				if (ti != s.begin()) {
					ti--;
				}
				if (it != s.end() && abs(*it - x) < abs(x - *ti)) {
					ti = it;
				}
				printf("%d\n", *ti);
				s.erase(ti);
			} else {
				printf("Empty\n");
			}
		}
	}
	return 0;
}