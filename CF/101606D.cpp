#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > z;
string s;
int main() {
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		char ch = s[i];
		int index = i;
		for (int j = i + 1; j < s.size(); j++) {
			if (s[j] < ch) {
				ch = s[j];
				index = j;
			}
		}
		if (index == i) {
			continue;
		}
		swap(s[i], s[index]);
		z.push_back(make_pair(index, i));
	}
	for (int i = z.size() - 1; i >= 0; i--) {
		printf("%d %d\n", z[i].first + 1, z[i].second + 1);
	}
}