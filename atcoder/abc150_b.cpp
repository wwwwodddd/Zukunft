#include <bits/stdc++.h>
using namespace std;
int n, z;
string s;
int main()
{
	cin >> n >> s;
	for (int i = 0; i + 2 < n; i++)
	{
		if (s.substr(i, 3) == "ABC")
		{
			z++;
		}
	}
	cout << z << endl;
	return 0;
}
