#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, 2, 1, 2, -1, -2, -1, -2};
int dy[] = {2, 1, -2, -1, 2, 1, -2, -1};
int main()
{
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (x1 + dx[i] + dx[j] == x2 && y1 + dy[i] + dy[j] == y2)
			{
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
