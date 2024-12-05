#include <bits/stdc++.h>
using namespace std;
int p1, p2, p3;
string s, z;
int main()
{
	cin >> p1 >> p2 >> p3 >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '-' && 0 < i && i + 1 < s.size() && s[i - 1] < s[i + 1] &&
			(isdigit(s[i - 1]) && isdigit(s[i + 1]) ||
			 islower(s[i - 1]) && islower(s[i + 1])))
		{
			string t;
			for (char j = s[i - 1] + 1; j < s[i + 1]; j++)
			{
				for (int k = 0; k < p2; k++)
				{
					t += j;
				}
			}
			if (p1 == 2)
			{
				for (int i = 0; i < t.size(); i++)
				{
					t[i] = toupper(t[i]);
				}
			}
			else if (p1 == 3)
			{
				for (int i = 0; i < t.size(); i++)
				{
					t[i] = '*';
				}
			}
			if (p3 == 2)
			{
				reverse(t.begin(), t.end());
			}
			z += t;
		}
		else
		{
			z += s[i];
		}
	}
	cout << z << endl;
	return 0;
}