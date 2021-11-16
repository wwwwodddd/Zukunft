#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
	cin >> s;
	int z = 753;
	for (int i = 2; i < s.size(); i++)
	{
		z = min(z, abs((s[i - 2] - '0') * 100 + (s[i - 1] - '0') * 10 + (s[i] - '0') - 753));
	}
	cout << z << endl;
	return 0;
}
