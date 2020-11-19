#include <cstdio>
#include <set>
using namespace std;
multiset<int> s;
int n, x, y;
int main() {
	for (;~scanf("%d", &n);) {
		s.clear();
		for (;n--;) {
			scanf("%d", &x);
			if (x == 1) {
				scanf("%d", &y);
				s.insert(y);
			} else if (x == 2) {
				if (s.size() > 0) {
					s.erase(s.begin());
				}
			} else {
				if (s.size() == 0) {
					printf("0\n");
				} else {
					printf("%d\n", *--s.end());
				}
			}
		}
	}
	return 0;
}