#include <bits/stdc++.h>
using namespace std;
string s;
int n, z;
char l = 'H';
int main()
{
	cin >> n >> s;
	for (int i = s.size() - 2; i >= 0; i -= 2)
	{
		if (s[i] != s[i + 1])
		{
			if (l != s[i])
			{
				l = s[i];
				z++;
			}
		}
	}
	cout << z << endl;
	return 0;
}