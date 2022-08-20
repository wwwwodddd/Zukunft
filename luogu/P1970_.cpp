#include <bits/stdc++.h>
using namespace std;
int n, x;
int s[100020], ss;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (ss == 0)
		{
			s[ss++] = x;
		}
		else if (s[ss - 1] == x)
		{
			
		}
		else if (ss == 1) //  && s[ss - 1] != x
		{
			s[ss++] = x;
		}
		else if (s[ss - 1] < s[ss - 2] && s[ss - 1] < x)
		{
			s[ss++] = x;
		}
		else if (s[ss - 1] > s[ss - 2] && s[ss - 1] > x)
		{
			s[ss++] = x;
		}
		else
		{
			s[ss - 1] = x;
		}
	}
	cout << ss << endl;
	return 0;
}
