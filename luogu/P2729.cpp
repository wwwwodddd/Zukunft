#include <bits/stdc++.h>
using namespace std;
int main()
{
	int vi, vj, vk, ai, aj, ak, bi, bj, bk, ci, cj, ck;
	cin >> vi >> vj >> vk >> ai >> aj >> ak >> bi >> bj >> bk >> ci >> cj >> ck;
	for (int a = 0; a < 100; a++)
	{
		for (int b = 0; b < 100; b++)
		{
			for (int c = 0; c < 100; c++)
			{
				if (a + b + c)
				{
					int ui = a * ai + b * bi + c * ci;
					int uj = a * aj + b * bj + c * cj;
					int uk = a * ak + b * bk + c * ck;
					int r = max(max(ui, uj), uk) / max(max(vi, vj), vk);
					if (vi * r == ui && vj * r == uj && vk * r == uk)
					{
						printf("%d %d %d %d\n", a, b, c, r);
						return 0;
					}
				}
			}
		}
	}
	printf("NONE\n");
	return 0;
}