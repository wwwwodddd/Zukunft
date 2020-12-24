#include <bits/stdc++.h>
using namespace std;
int z, a[26]={1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};
string s;
int main()
{
	getline(cin, s);
	for (int i: s)
	{
		if (isalpha(i))
		{
			z += a[i - 'a'];
		}
		else if (i == ' ')
		{
			z++;
		}
	}
	cout << z << endl;
	return 0;
}