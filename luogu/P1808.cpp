#include <bits/stdc++.h>
using namespace std;
set<string> ss;
string s;
int n;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		sort(s.begin(), s.end());
		ss.insert(s); 
	}
	cout << ss.size() << endl;
	return 0;
}