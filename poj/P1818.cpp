#include <stdio.h>
#include<string.h>
#define max(a,b) ((a)>(b)?(a):(b))

int n, x, k, queue[5010], add; char elio[5010];

int vali (int person)
{
    int i, j, kase, tail, t;
    memset(elio, 0, sizeof(elio));
    elio[person] = 1; tail = person;
    add = 0; queue[add++] = person;
    for (kase = 1; kase <= x; kase++)
    {
        t = add;
        for (i = 0; i < t; i++)
        {
            for (j = max(1, queue[i] - k); j <= tail; j++)
            {
                if (elio[j] == 0)
                {
                   elio[j] = kase + 1;
                   queue[add++] = j;
                   break;
                }
            }
        }
    }
    for (i = 1; i <= tail; i++)
        if (elio[i] == 0) return 0;
    return 1;
}

int main ()
{
    int st, ed, mid, i,pst=0;
	n=512;
	for(k=1;k<80;k++)
	{
		for (x = 0, i = 1; i < n; x++, i *= 2);
		st = 1, ed = n;
		if (vali(ed)) st = ed;
		else while (ed - st > 1)
		{
			 mid = (st + ed) >> 1;
			 if (vali(mid)) st = mid;
			 else ed = mid;
		}
		printf("%d %d %d\n", st,k,st-pst);
		getchar();
		pst=st;
	}
	return 0;
}
