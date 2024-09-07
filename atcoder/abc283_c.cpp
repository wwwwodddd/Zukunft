#include <bits/stdc++.h>
using namespace std;
string s;
int z;
int main()
{
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		z++;
		if (i + 1 < s.size() && s[i] == '0' && s[i + 1] == '0')
		{
			i++;
		}
	}
	cout << z << endl;
	return 0;
}
