#include <bits/stdc++.h>
using namespace std;
string s;
long long n, z, c = 1;
int main()
{
	cin >> n >> s;
	for (int i = 1; i < n; i++)
	{
		if (s[i] == s[i - 1])
		{
			z += c++;
		}
		else
		{
			c = 1;
		}
	}
	cout << z << endl;
	return 0;
}
