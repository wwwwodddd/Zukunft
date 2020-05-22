#include <bits/stdc++.h>
using namespace std;
vector<string> a;
string s;
int k;
int main() {
	cin >> s >> k;
	for (int i = 0; i < s.size(); i++) {
		for (int j = 1; j <= k && i + j <= s.size(); j++) {
			a.push_back(s.substr(i, j));
		}
	}
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());
	cout << a[k - 1] << endl;
	return 0;
}