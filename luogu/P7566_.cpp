#include <bits/stdc++.h>
using namespace std;
int n;
long long M, C, O, I;
string s;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (s[0] == 'M')
		{
			M++;
		}
		else if (s[0] == 'C')
		{
			C++;
		}
		else if (s[0] == 'O')
		{
			O++;
		}
		else if (s[0] == 'I')
		{
			I++;
		}
	}
	cout << M * C * O + M * C * I + M * O * I + C * O * I << endl;
	return 0;
}