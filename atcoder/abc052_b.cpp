#include <bits/stdc++.h>
using namespace std;
string s;
int n, x, z;
int main()
{
	cin >> n;
	cin >> s;
	for (char c:s)
	{
		z = max(z, c == 'I' ? ++x : --x);
	}
	cout << z << endl;
	return 0;
}
