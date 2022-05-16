#include <bits/stdc++.h>
using namespace std;
string s;
int v[1000000], z;
int main()
{
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		int x = 0;
		for (int j = i; j < s.size() && j < i + 6; j++)
		{
			x = 10 * x + s[j] - '0';
			v[x] = 1;
		}
	}
	while (v[z])
	{
		z++;
	}
	cout << z << endl;
	return 0;
}