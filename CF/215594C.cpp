#include <bits/stdc++.h>
using namespace std;
string s;
bool endwith(string a, string b) {
	return a.size() >= b.size() && a.substr(a.size() - b.size(), b.size()) == b;
}
int main() {
	cin >> s;
	if (endwith(s, "nt")) {
		printf("3rd person plural\n");
	} else if (endwith(s, "tis")) {
		printf("2nd person plural\n");
	} else if (endwith(s, "mus")) {
		printf("1st person plural\n");
	} else if (endwith(s, "t")) {
		printf("3rd person singular\n");
	} else if (endwith(s, "s")) {
		printf("2nd person singular \n");
	} else if (endwith(s, "o")) {
		printf("1st person singular\n");
	}
	return 0;
}