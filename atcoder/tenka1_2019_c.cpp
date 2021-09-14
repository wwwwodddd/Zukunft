#include <bits/stdc++.h>
using namespace std;
int n, c, z;
char s[200020];
int main()
{
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '.')
		{
			c++;
		}
	}
	z = c;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '.')
		{
			c--;
		}
		else
		{
			c++;
		}
		z = min(z, c);
	}
	cout << z << endl;
	return 0;
}