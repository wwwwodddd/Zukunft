#include <bits/stdc++.h>
using namespace std;
long long n;
string s;
int main()
{
	cin >> n;
	while (n)
	{
		s = char((n - 1) % 26 + 'a') + s;
		n = (n - 1) / 26;
	}
	cout << s << endl;
	return 0;
}
