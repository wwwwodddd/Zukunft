#include <bits/stdc++.h>
using namespace std;
string s;
int z;
int main() {
	cin >> s;
	s += "1";
	for (int i = 1; i < s.size(); i++) {
		z += (s[i - 1] != s[i]);
	}
	printf("%d\n", z);
	return 0;
}
