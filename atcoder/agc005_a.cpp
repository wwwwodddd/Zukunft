#include <bits/stdc++.h>
using namespace std;
string a;
int t, s;
int main()
{
	cin >> a;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == 'T')
		{
			if (s > 0)
			{
				s--;
			}
			else
			{
				t++;
			}
		}
		else
		{
			s++;
		}
	}
	cout << s + t << endl;
	return 0;
}
