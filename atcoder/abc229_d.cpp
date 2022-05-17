#include <bits/stdc++.h>
using namespace std;
string s;
int k, cnt, z;
int main()
{
	cin >> s >> k;
	for (int i = 0, j = 0; j < s.size();)
	{
		k -= s[j++] == '.';
		while (k < 0)
		{
			k += s[i++] == '.';
		}
		z = max(z, j - i);
	}
	cout << z << endl;
	return 0;
}
