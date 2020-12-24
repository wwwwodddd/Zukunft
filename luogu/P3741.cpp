#include <bits/stdc++.h>
using namespace std;
int n, z;
string s;
int main()
{
	cin >> n >> s;
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i] == 'K' && s[i - 1] == 'V')
		{
			z++;
			s[i] = s[i - 1] = 0;
		}
	}
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i] != 0 && s[i] == s[i - 1])
		{
			z++;
			break;
		}
	}
	printf("%d\n", z);
	return 0;
}