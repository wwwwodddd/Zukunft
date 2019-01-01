#include <bits/stdc++.h>
using namespace std;
int t;
string s;
int main() {
	cin >> t;
	for (int tt = 0; tt < t; tt++) {
		cin >> s;
		if (s[s.size() - 1] & 1) {
			printf("odd\n");
		} else {
			printf("even\n");
		}
	}
	return 0;
}
