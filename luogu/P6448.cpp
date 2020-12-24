#include <bits/stdc++.h>//头文件
using namespace std;
int a[5];
int main()
{
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &a[i]);
	}
	while (!is_sorted(a, a + 5))
	{
		for (int i = 1; i < 5; i++)
		{
			if (a[i - 1] > a[i])
			{
				swap(a[i - 1], a[i]);
				for (int j = 0; j < 5; j++)
				{
					printf("%d%c", a[j], j == 4 ? '\n' : ' ');
				}
			}
		}
	}
	return 0;
}