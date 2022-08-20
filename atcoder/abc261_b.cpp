#include <bits/stdc++.h>
using namespace std;
int n;
string a[1020];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[i][j] == 'D' && a[j][i] == 'D')
			{
				
			}
			else if (a[i][j] == 'W' && a[j][i] == 'L')
			{
				
			}
			else if (a[i][j] == 'L' && a[j][i] == 'W')
			{
				
			}
			else
			{
				cout << "incorrect" << endl;
				return 0;
			}
		}
	}
	cout << "correct" << endl;
	return 0;
}
