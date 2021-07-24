#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main()
{
	cin >> n >> s;
	cout << (s.find('1') & 1 ? "Aoki" : "Takahashi") << endl;
	return 0;
}
