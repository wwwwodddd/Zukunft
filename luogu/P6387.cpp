#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
	cin >> s;
	cout << (next_permutation(s.begin(), s.end()) ? s : "0") << endl;
	return 0;
}