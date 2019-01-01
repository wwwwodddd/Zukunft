#include <bits/stdc++.h>
using namespace std;
string a, b;
int main() {
	getline(cin, a);
	getline(cin, b);
	for (int i = 0; i < a.size(); i++) {
		a[i] = tolower(a[i]);
	}
	for (int i = 0; i < b.size(); i++) {
		b[i] = tolower(b[i]);
	}
	a = " " + a + " ";
	b = " " + b + " ";
	int cnt = 0, first = -1;
	for (int i = 0; i + a.size() <= b.size(); i++) {
		if (a == b.substr(i, a.size())) {
			if (cnt == 0) {
				first = i;
			}
			cnt++;
		}
	}
	if (cnt == 0) {
		printf("-1\n");
	} else {
		printf("%d %d\n", cnt, first);
	}
	return 0;
}

