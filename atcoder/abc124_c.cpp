#include <bits/stdc++.h>
using namespace std;
size_t z;
string s;
int main()
{
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] + i & 1)
		{
			z++;
		}
	}
	cout << min(z, s.size() - z) << endl;
	return 0;
}
