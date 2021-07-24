#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
	cin >> s;
	puts(~s.find("0000000") || ~s.find("1111111") ? "YES" : "NO");
}
