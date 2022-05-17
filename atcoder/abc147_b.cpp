#include <bits/stdc++.h>
using namespace std;
string s;
int z;
int main()
{
	cin >> s;
	for (int i = 0; i < s.size() - 1 - i; i++)
	{
		if (s[i] != s[s.size() - 1 - i])
		{
			z++;
		}
	}
	cout << z << endl;
}
