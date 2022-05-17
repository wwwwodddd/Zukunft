#include <bits/stdc++.h>
using namespace std;
unsigned k;
string s;
int main()
{
	cin >> k >> s;
	cout << (s.size() > k ? s.substr(0, k) + "..." : s) << endl;
}
