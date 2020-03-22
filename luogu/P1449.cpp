#include <bits/stdc++.h>
using namespace std;
char c;
int v;
stack<int> s;
int main() {
	while (cin >> c) {
		if (c == '.') {
			s.push(v);
			v = 0;
		} else if (isdigit(c)) {
			v = v * 10 + c - '0';
		} else if (c == '@') {
			break;
		} else {
			int y = s.top();
			s.pop();
			int x = s.top();
			s.pop();
			if (c == '+') {
				s.push(x + y);
			} else if (c == '-') {
				s.push(x - y);
			} else if (c == '*') {
				s.push(x * y);
			} else if (c == '/') {
				s.push(x / y);
			}
		}
	}
	cout << s.top() << endl;
}