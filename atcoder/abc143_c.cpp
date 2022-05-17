#include <bits/stdc++.h>
using namespace std;
int n;
char s[100020];
int main()
{
	cin >> n >> s;
	cout << unique(s, s + n) - s << endl;
	return 0;
}
